import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
from std_msgs.msg import String, Float32
from yolov8_msgs.msg import DetectionArray


class ImageSubscriber(Node):

    def __init__(self):
        super().__init__('image_subscriber')

        # Subscribers
        self.subscription = self.create_subscription(
            Image,
            '/yolo/dbg_image_human',
            self.listener_callback,
            10)
        self.br = CvBridge()

        self.subscribePersonPos = self.create_subscription(
            DetectionArray,
            '/yolo/detections_human',
            self.listener_callback_personPos,
            10)

        # Publishers
        self.direction_publisher = self.create_publisher(
            String, '/robot/direction', 10)

        self.velocity_publisher = self.create_publisher(
            Float32, '/robot/velocity', 10)

    def listener_callback(self, data):
        """Callback to visualize the camera feed with the regions marked."""
        self.get_logger().info('Receiving video frame')
        current_frame = self.br.imgmsg_to_cv2(data)

        height, width = current_frame.shape[:2]

        # Define regions (5 parts with leftmost and rightmost half-sized)
        region_width = width // 4
        leftmost_width = region_width // 2
        rightmost_width = region_width // 2

        # Draw region boundaries
        cv2.line(current_frame, (leftmost_width, 0), (leftmost_width, height), (0, 255, 0), 3)
        cv2.line(current_frame, (leftmost_width + region_width, 0), 
                 (leftmost_width + region_width, height), (0, 255, 0), 3)
        cv2.line(current_frame, (leftmost_width + 2 * region_width, 0), 
                 (leftmost_width + 2 * region_width, height), (0, 255, 0), 3)
        cv2.line(current_frame, (width - rightmost_width, 0), 
                 (width - rightmost_width, height), (0, 255, 0), 3)

        cv2.imshow("camera", current_frame)
        cv2.waitKey(1)

    def listener_callback_personPos(self, msg):
        """Callback to process detections and publish directions/velocities."""
        self.get_logger().info('Receiving person position data')
        
        if len(msg.detections) == 0:
            # No person detected, stop robot
            self.get_logger().info("No person detected, stopping robot.")
            self.publish_velocity(0.0)
            self.publish_direction("stop")
            return

        # Process first detected person (adjust if needed for multiple detections)
        posX = msg.detections[0].bbox.center.position.x
        bbox_width = msg.detections[0].bbox.size.x  # Width of bounding box (distance proxy)

        # Determine direction and publish
        region = self.get_region(posX)
        self.publish_direction(region)

        # Calculate velocity and publish
        velocity = self.calculate_velocity(bbox_width)
        self.publish_velocity(velocity)

    def get_region(self, posX):
        """Determine which region the X position belongs to."""
        # Define boundaries for regions
        width = 1200  # Assumed total width of the frame
        region_width = width // 4  # Calculate width for the middle three regions
        leftmost_width = region_width // 2
        rightmost_width = region_width // 2

        if posX < leftmost_width:
            return 'turn_left'
        elif posX < leftmost_width + region_width:
            return 'turn_left_30'
        elif posX < leftmost_width + 2 * region_width:
            return 'go_straight'
        elif posX < width - rightmost_width:
            return 'turn_right_30'
        else:
            return 'turn_right'

    def calculate_velocity(self, bbox_width):
        """Calculate velocity based on bounding box width."""
        # Assume that a larger bounding box width indicates closer proximity
        max_bbox_width = 300  # Width when the person is very close
        min_bbox_width = 50   # Width when the person is far away
        max_velocity = 1.0    # Maximum velocity
        min_velocity = 0.1    # Minimum velocity

        if bbox_width >= max_bbox_width:
            return min_velocity  # Person is too close, slow down
        elif bbox_width <= min_bbox_width:
            return max_velocity  # Person is far, speed up
        else:
            # Linearly interpolate between min and max velocity
            return max_velocity - (bbox_width - min_bbox_width) * (max_velocity - min_velocity) / (max_bbox_width - min_bbox_width)

    def publish_direction(self, direction):
        """Publish the direction command."""
        direction_msg = String()
        direction_msg.data = direction
        self.direction_publisher.publish(direction_msg)
        self.get_logger().info(f"Published direction: {direction}")

    def publish_velocity(self, velocity):
        """Publish the velocity to the motor controller."""
        velocity_msg = Float32()
        velocity_msg.data = velocity
        self.velocity_publisher.publish(velocity_msg)
        self.get_logger().info(f"Published velocity: {velocity}")


def main(args=None):
    rclpy.init(args=args)
    image_subscriber = ImageSubscriber()
    rclpy.spin(image_subscriber)
    image_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
