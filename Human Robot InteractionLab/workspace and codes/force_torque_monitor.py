#!/usr/bin/env python3

"""
Script that monitors the joint torques. If threshold is exceeded, a vector with
the new motion direction of the end effector is computed as desired input for 
the admittance controller
"""

import rospy
import numpy as np
from std_msgs.msg import Float64MultiArray
from geometry_msgs.msg import WrenchStamped
from franka_msgs.msg import FrankaState


class Node(object):

    def __init__(self):

        self.joint_torques = np.zeros(7)
        self.F_offset = np.zeros(3)
        self.F_ext = np.zeros(3)	
        self.motion_direction = Float64MultiArray()
        self.motion_direction.data = np.zeros(3)
        self.cartesian_rotation = np.zeros((3,3))
        
        # Torque thresholds
        self.torque_thresholds = np.array([5.0, 4.0, 4.0, 4.0, 2.5, 2.5, 2.0])
        
        # Get the intial force offset values
        rospy.sleep(2.)
        wrench = rospy.wait_for_message("franka_state_controller/F_ext", WrenchStamped)
        self.F_offset = [wrench.wrench.force.x, wrench.wrench.force.y, wrench.wrench.force.z]
        rospy.sleep(1.)
        
        # Initialize the Subscribers to the external torques, forces and cartesian position
        self.sub_F_ext = rospy.Subscriber("franka_state_controller/F_ext", WrenchStamped, self.F_ext_callback)
        self.sub_joint_torques = rospy.Subscriber("/franka_state_controller/franka_states", FrankaState, self.joint_torques_callback)
        self.sub_cart_pos = rospy.Subscriber("franka_state_controller/franka_states", FrankaState, self.cart_pos_callback)
        
        # Initialize the Publisher for the calculated motion direction as input for the admittance control
        self.pub_motion_direction = rospy.Publisher("motion_direction", Float64MultiArray, queue_size=10) 


    def check_torque_limits(self):
        """
        Function that supervices the joint torques.
        If the magnitudes of single torque values reach a limit,
        return True
        #TODO: Implement monitoring the joint torques here
        """        
        limit_exceeded = False
        
        for i in range(1,len(self.torque_thresholds)):
            if abs(self.joint_torques[i])>self.torque_thresholds[i]:
                limit_exceeded=True
                print("The limit has exceeded")
    
        return limit_exceeded


    def change_velocity_vector(self):
        """
        TODO: Change direction of motion vector (self.motion_direction).
        It should be a unit vector in same direction as current end effector 
        force vector.
        (Magnitude of a vector: np.linalg.norm())
        """
        
        self.motion_direction.data = self.F_ext/(np.linalg.norm(self.F_ext))
        print("Direction changed!")
        print(self.motion_direction.data)

    
    def F_ext_callback(self, msg):
        """
        Function that reads measured forces on end effector into variable.
        Setting to zero with subtracting the initial offset.
        Transforming into base frame
        """
        # Get the force components in x, y and z to the vector self.F_ext
        self.F_ext[0] = msg.wrench.force.x
        self.F_ext[1] = msg.wrench.force.y
        self.F_ext[2] = msg.wrench.force.z
        self.F_ext = np.matmul(self.cartesian_rotation, (self.F_offset - self.F_ext))


    def cart_pos_callback(self, msg):
        """
        Getting the rotation of the end effector from the transformation 'O_T_EE'.
        """
        O_T_EE = msg.O_T_EE
        O_T_EE = np.transpose(np.reshape(O_T_EE, (4, 4)))
        self.cartesian_rotation = O_T_EE[0:3, 0:3]
        
        
    def joint_torques_callback(self, msg):
        """
        The vector "tau_ext_hat_filtered" of the Franka States gives
        the external torques acting on the robot.
        
        TODO: Get the measured joint torques
        """
        self.joint_torques = msg.tau_ext_hat_filtered


    def run(self):
        
        rate = rospy.Rate(10)
        
        while not rospy.is_shutdown():
            # Check for joint torque limits
            limit_exceeded = self.check_torque_limits()
            
            # Change robot motion if limit exceeded
            if limit_exceeded == True:
                self.change_velocity_vector()
            
            # Publish the motion direction
            self.pub_motion_direction.publish(self.motion_direction) 
                        
            rate.sleep()


if __name__ == "__main__":
    rospy.init_node("force_monitor_node")
    n = Node()
    n.run()
