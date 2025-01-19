import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from collections import deque  # Para manter histórico das últimas leituras
from std_msgs.msg import String, Float32
import asyncio
import time
import math


class Navigation(Node):
    def __init__(self):
        super().__init__('navigator')
        print("[Navigator] Inicializando nó de navegação...")

        # Publicador para enviar comandos de velocidade para o robô
        self.velocity_publisher = self.create_publisher(Twist, '/hoverboard_base_controller/cmd_vel_unstamped', 10)
        print("[Navigator] Publicador '/cmd_vel' criado.")

        # Assinatura do tópico do LiDAR
        self.scan_subscription = self.create_subscription(LaserScan, '/scan', self.lidar_callback, 10)
        print("[Navigator] Assinatura do tópico '/scan' criada.")

        self.twist = Twist()  # Objeto para armazenar comandos de velocidade
        print("[Navigator] Objeto Twist inicializado.")

        # Inscrição no tópico /robot/direction
        self.direction_subscription = self.create_subscription(
            String,
            '/robot/direction',
            self.direction_callback,  # Função de callback
            10
        )

        # Inscrição no tópico /robot/velocity
        self.velocity_subscription = self.create_subscription(
            Float32,
            '/robot/velocity',
            self.velocity_callback,  # Função de callback
            10
        )

        self.right_history = deque(maxlen=5)
        self.left_history = deque(maxlen=5)

        self.front_history = deque(maxlen=3)

        self.safe_distance_front = 0.20

        self.safe_distance = 0.4
        
        self.time_to_turn_flag = False  # Flag para indicar se o robô está aguardando para virar
        
        # Inicializa valores mais recentes recebidos dos tópicos
        self.latest_direction = None
        self.latest_velocity = None

        # Inicializa o controle de tempo de giro
        self.turn_start_time = None  # Armazena o tempo de início do giro


    def lidar_callback(self, msg):
        ranges = msg.ranges
        angle_increment = msg.angle_increment
        angle_min = msg.angle_min
        num_readings = len(ranges)

        # Definir setores para análise
        sectors = {
            "back": (315, 45),
            "right": (45, 135),
            "front": (135, 225),
            "left": (225, 315)
        }

        def get_indices_for_sector(start_angle, end_angle):
            indices = []
            for i in range(num_readings):
                angle = (angle_min + i * angle_increment) * 180 / 3.14159  # Converter para graus
                angle = angle % 360  # Garantir que os ângulos fiquem entre 0 e 360
                if start_angle <= end_angle:
                    if start_angle <= angle <= end_angle:
                        indices.append(i)
                else:  # Setor que cruza 0° (ex.: 315° a 45°)
                    if angle >= start_angle or angle <= end_angle:
                        indices.append(i)
            return indices

        sector_min_distances = {}
        for sector, (start, end) in sectors.items():
            indices = get_indices_for_sector(start, end)
            valid_readings = [ranges[i] for i in indices if ranges[i] > 0.0]
            min_distance = min(valid_readings) if valid_readings else float('inf')
            sector_min_distances[sector] = min_distance

        # Atualizar histórico das leituras dos setores direito e esquerdo
        right_indices = get_indices_for_sector(*sectors["right"])
        left_indices = get_indices_for_sector(*sectors["left"])
        front_indices = get_indices_for_sector(*sectors["front"])

        right_readings = [ranges[i] for i in right_indices if ranges[i] > 0.0]
        left_readings = [ranges[i] for i in left_indices if ranges[i] > 0.0]
        front_readings = [ranges[i] for i in front_indices if ranges[i] > 0.0]

        self.right_history.append(min(right_readings) if right_readings else float('inf'))
        self.left_history.append(min(left_readings) if left_readings else float('inf'))
        self.front_history.append(min(front_readings) if front_readings else float('inf'))

        # Exibir as distâncias mínimas de cada setor
        for sector, distance in sector_min_distances.items():
            if distance == float('inf'):
                self.get_logger().info(f"{sector.capitalize()}: ERRO nas leituras")
            else:
                self.get_logger().info(f"{sector.capitalize()}: {distance:.2f} metros")

        # Verificar necessidade de ajustes
        self.check_and_adjust()

    def check_and_adjust(self):
        # Ajustar o robô com base na distância das paredes
        if all(distance == self.safe_distance_front for distance in self.front_history):
            self.get_logger().info("[LIDAR] Objeto a frente. Parando...")
            self.stop()
        elif all(distance < self.safe_distance for distance in self.right_history):
            self.get_logger().info("[LIDAR] Parede muito próxima à direita. Ajustando...")
            self.avoid_wall("left")
        elif all(distance < self.safe_distance for distance in self.left_history):
            self.get_logger().info("[LIDAR] Parede muito próxima à esquerda. Ajustando...")
            self.avoid_wall("right")
        else:
            self.get_logger().info("[LIDAR] Nenhum ajuste necessário. Movendo para frente.")
            #self.move_forward()

    def avoid_wall(self, direction):
        # Ajustar a direção para evitar a parede
        if direction == "left":
            self.twist.linear.x = 0.1  # Movimento linear mais lento
            self.twist.angular.z = 0.1  # Rotação para a esquerda
        elif direction == "right":
            self.twist.linear.x = 0.1
            self.twist.angular.z = -0.1  # Rotação para a direita
        self.velocity_publisher.publish(self.twist)

    def go_backwards(self):
        # Ajustar a velocidade para dar ré
        self.twist.linear.x = -0.2
        self.twist.angular.z = 0.0  
        self.velocity_publisher.publish(self.twist)

    def stop(self):
        # Configuração para mover o robô para frente
        self.twist.linear.x = 0.0
        self.twist.angular.z = 0.0
        self.velocity_publisher.publish(self.twist)

    def direction_callback(self, msg):
        # Atualiza o valor mais recente da direção
        self.latest_direction = msg.data
        self.get_logger().info(f'Direção recebida: {self.latest_direction}')
        self.send_velocity_orientacion()

    def velocity_callback(self, msg):
        # Atualiza o valor mais recente da velocidade
        self.latest_velocity = msg.data
        #self.get_logger().info(f'Velocidade recebida: {self.latest_velocity}')
        self.send_velocity_orientacion()

    def send_velocity_orientacion(self):
        # Imprime a velocidade apenas se a direção for "go_straight"
        if self.latest_direction == "stop" and self.latest_velocity is not None:
            self.stop()
        elif self.latest_velocity is not None and self.latest_velocity < 0.01:
            self.get_logger().info("Objeto muito próximo. Movendo para trás...")
            self.go_backwards()
        elif self.latest_direction == "go_straight" and self.latest_velocity is not None:
            self.get_logger().info('Seguindo em linha reta.')
            self.twist.linear.x = (self.latest_velocity * 3)
            self.twist.angular.z = 0.0
            self.velocity_publisher.publish(self.twist)
        elif self.latest_direction == "turn_left" and self.latest_velocity is not None:
            self.time_to_turn_flag = True
            self.get_logger().info("Rodando 90° para esquerda.")
            self.time_to_turn(-0.7)
        elif self.latest_direction == "turn_right" and self.latest_velocity is not None:
            self.time_to_turn_flag = True
            self.get_logger().info("Rodando 90° para direita.")
            self.time_to_turn(0.7)    
        elif self.latest_direction == "turn_left_30" and self.latest_velocity is not None:
            self.time_to_turn_flag = True
            self.get_logger().info("Ajustando 30° para esquerda.")
            self.time_to_turn(-0.3)
        elif self.latest_direction == "turn_right_30" and self.latest_velocity is not None:
            self.time_to_turn_flag = True
            self.get_logger().info("Ajustando 30° para direita.")
            self.time_to_turn(0.3)

        else:
            self.get_logger().info('SEM DIRECAO')

    def time_to_turn(self, vel):
        if not self.turn_start_time:
            self.turn_start_time = self.get_clock().now()

        elapsed_time = (self.get_clock().now() - self.turn_start_time).nanoseconds / 1e9
        if elapsed_time < 2.0:
            self.twist.linear.x = 0.0
            self.twist.angular.z = -1.0 * vel
            self.velocity_publisher.publish(self.twist)
            self.get_logger().info("PUBLICANDO VELOCIDADE DE GIRO")

        else:
            self.time_to_turn_flag = False
            self.turn_start_time = None
            self.stop()  # Para o robô após completar o giro

        

def main(args=None):
    rclpy.init(args=args)
    node = Navigation()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()