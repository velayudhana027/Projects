#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, TransformStamped
from sensor_msgs.msg import JointState
from tf2_ros import TransformBroadcaster
import math

class HumanoidGaitGenerator(Node):
    def __init__(self):
        super().__init__('humanoid_gait_generator')
        
        # Publishers and Broadcasters
        self.br = TransformBroadcaster(self)
        self.joint_pub = self.create_publisher(JointState, 'joint_states', 10)
        self.cmd_sub = self.create_subscription(Twist, 'cmd_vel', self.cmd_cb, 10)
        
        # State Variables
        self.x, self.y, self.th = 0.0, 0.0, 0.0  # Position in odom frame
        self.vx, self.vth = 0.0, 0.0            # Commanded velocities
        self.phase = 0.0                        # Animation phase
        
        # Timer for 50Hz update (smooth movement)
        self.timer = self.create_timer(0.02, self.update_logic)

    def cmd_cb(self, msg):
        """Update velocity commands from teleop"""
        self.vx = msg.linear.x
        self.vth = msg.angular.z

    def update_logic(self):
        now = self.get_clock().now().to_msg()
        dt = 0.02

        # --- 1. ODometry LOGIC (Movement through space) ---
        self.th += self.vth * dt
        self.x += self.vx * math.cos(self.th) * dt
        self.y += self.vx * math.sin(self.th) * dt

        # Publish the transform from odom to the robot base (pelvis)
        t = TransformStamped()
        t.header.stamp = now
        t.header.frame_id = 'odom'
        t.child_frame_id = 'pelvis'
        t.transform.translation.x = self.x
        t.transform.translation.y = self.y
        t.transform.translation.z = 0.78  # Standing height
        t.transform.rotation.z = math.sin(self.th / 2.0)
        t.transform.rotation.w = math.cos(self.th / 2.0)
        self.br.sendTransform(t)

        # --- 2. GAIT LOGIC (Moving the limbs) ---
        js = JointState()
        js.header.stamp = now
        js.name = [
            'left_hip_pitch_joint', 'right_hip_pitch_joint',
            'left_knee_joint', 'right_knee_joint',
            'left_ankle_pitch_joint', 'right_ankle_pitch_joint',
            'left_shoulder_pitch_joint', 'right_shoulder_pitch_joint',
            'left_elbow_joint', 'right_elbow_joint'
        ]

        if abs(self.vx) > 0.01 or abs(self.vth) > 0.01:
            # Synchronized phase: Faster command = faster animation
            self.phase += (abs(self.vx) * 6.0 + 2.0) * dt
            
            swing = math.sin(self.phase) * 0.45
            knee = (math.sin(self.phase - 1.5) + 1.1) * 0.5
            
            js.position = [
                swing,          # L Hip
                -swing,         # R Hip
                knee,           # L Knee
                (math.sin(self.phase + 1.5) + 1.1) * 0.5, # R Knee
                -swing * 0.3,   # L Ankle
                swing * 0.3,    # R Ankle
                -swing * 0.8,   # L Shoulder (Opposite of L Hip)
                swing * 0.8,    # R Shoulder
                0.4, 0.4        # Elbows
            ]
        else:
            # Reset to idle pose when stopped
            js.position = [0.0] * len(js.name)
            self.phase = 0.0

        self.joint_pub.publish(js)

def main(args=None):
    rclpy.init(args=args)
    node = HumanoidGaitGenerator()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()