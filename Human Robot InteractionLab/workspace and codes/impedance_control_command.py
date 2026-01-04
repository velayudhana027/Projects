#!/usr/bin/env python3

"""
Command Node for the target position for impedance control of the Franka Emika 
robot. Formulated in cartesian space for three directions x, y and z. 
No angular motion (commanded angular position constant).
"""

import rospy
import numpy as np
from std_msgs.msg import Float64MultiArray
from franka_msgs.msg import FrankaState
from geometry_msgs.msg import PoseStamped
import tf.transformations

class Node(object):

    def __init__(self):

        # Variables for robot motion (for Exercise 14-16):
        self.motion_direction = np.zeros(3)
        self.gain_p_d = 0.00015

        rospy.sleep(1.)

        # Get initial position. Initial position is preset to p_d.
        self.p_d = PoseStamped()
        franka_state = rospy.wait_for_message("franka_state_controller/franka_states", FrankaState)
        O_T_EE = franka_state.O_T_EE
        initial_quaternion = tf.transformations.quaternion_from_matrix(np.transpose(np.reshape(O_T_EE, (4, 4))))
        initial_quaternion = initial_quaternion / np.linalg.norm(initial_quaternion)
        self.p_d.pose.orientation.x = initial_quaternion[0]
        self.p_d.pose.orientation.y = initial_quaternion[1]
        self.p_d.pose.orientation.z = initial_quaternion[2]
        self.p_d.pose.orientation.w = initial_quaternion[3]
        self.p_d.pose.position.x = O_T_EE[12]
        self.p_d.pose.position.y = O_T_EE[13]
        self.p_d.pose.position.z = O_T_EE[14]

        rospy.sleep(1.)

        # Initialize Publishers
        """
        TODO Publish the desired position message to '/cartesian_impedance_example_controller/equilibrium_pose':
        """
        self.p_d_pub = rospy.Publisher('/cartesian_impedance_example_controller/equilibrium_pose', PoseStamped, queue_size=10)

        # Initialize Subscribers to motion direction (Exercise 14-16)
        self.sub_motion_direction = rospy.Subscriber("motion_direction", Float64MultiArray, self.motion_direction_callback)        

        rospy.sleep(1.)


    def motion_direction_callback(self, msg):
        """
        Get the desired motion direction
        """
        self.motion_direction = np.asarray(msg.data)


    def run(self):

        # ROS loop rate
        hz = 100

        rate = rospy.Rate(hz)

        while not rospy.is_shutdown():
            """
            Command function that updates and sends desired position.
            The x, y and z cartesian positions change continuously by a
            specified motion direction.
            """

            # Changing p_d along desired motion direction (self.motion_direction zero for early exercises)
            self.p_d.pose.position.x = self.p_d.pose.position.x + self.gain_p_d * self.motion_direction[0]
            self.p_d.pose.position.y = self.p_d.pose.position.y + self.gain_p_d * self.motion_direction[1]
            self.p_d.pose.position.z = self.p_d.pose.position.z + self.gain_p_d * self.motion_direction[2]
            
            self.p_d_pub.publish(self.p_d)

            rate.sleep()


if __name__ == "__main__":
    rospy.init_node("impedance_control_command")
    n = Node()
    n.run()
