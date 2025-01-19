import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
import numpy as np
import cv2

class LidarShapeDetector(Node):
    def __init__(self):
        super().__init__('lidar_shape_detector')
        self.subscription = self.create_subscription(
            LaserScan,
            '/scan',  # Substitua pelo tópico do seu LiDAR
            self.scan_callback,
            10)
        self.subscription

    def scan_callback(self, msg):
        # Converte os dados do LaserScan em coordenadas cartesianas
        ranges = np.array(msg.ranges)
        angles = np.linspace(msg.angle_min, msg.angle_max, len(ranges))
        
        # Filtra os pontos válidos
        mask = (ranges > msg.range_min) & (ranges < msg.range_max)
        ranges = ranges[mask]
        angles = angles[mask]
        
        # Converte para coordenadas X, Y
        x = ranges * np.cos(angles)
        y = ranges * np.sin(angles)
        
        # Cria uma imagem 2D para visualização
        image = self.create_lidar_image(x, y)
        
        # Detecta formas na imagem
        self.detect_circles(image)

    def create_lidar_image(self, x, y):
        # Normaliza os valores para caber em uma imagem
        scale = 100  # Fator de escala
        x_img = (x * scale + 500).astype(np.int32)
        y_img = (y * scale + 500).astype(np.int32)

        image = np.zeros((1000, 1000), dtype=np.uint8)
        for xi, yi in zip(x_img, y_img):
            if 0 <= xi < 1000 and 0 <= yi < 1000:
                image[yi, xi] = 255  # Pinta o ponto
        
        return image

    def detect_circles(self, image):
        # Aplica o método Hough Circle para detectar círculos
        circles = cv2.HoughCircles(image, cv2.HOUGH_GRADIENT, dp=1.2, minDist=20,
                                   param1=50, param2=30, minRadius=5, maxRadius=50)
        
        if circles is not None:
            circles = np.uint16(np.around(circles))
            for circle in circles[0, :]:
                center = (circle[0], circle[1])  # Coordenadas do centro
                radius = circle[2]  # Raio
                cv2.circle(image, center, radius, (255, 0, 0), 2)
            
            cv2.imshow('Detected Circles', image)
            cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    node = LidarShapeDetector()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

