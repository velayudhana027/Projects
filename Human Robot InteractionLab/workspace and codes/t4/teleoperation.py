#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Dec  4 14:38:52 2025

@author: asm-pc-7
"""


import numpy as np
import pygame
import time
import rospy

"""
ROS related libraries for second part
"""
from std_msgs.msg import Float64MultiArray
from std_msgs.msg import Float64
#import rospy


class Node(object):

    def __init__(self):

        # Variables
        self.gripper_width = 0.06
        self.mapped_force = 0.0
        self.cartesian_velocity = np.zeros(6)
        self.open_gripper = False
        self.close_gripper = False
        self.angular = False

        # Parameters
        self.rate = 1000
        self.k_gripper = 0.006 # Gain gripper position
        self.k_trans = 0.12 # Gain translations velocity
        self.k_rot = 0.3 # Gain rotational velocity
        
        # Pygame controls
        self.analog_keys = {0:0, 1:0, 2:0, 3:0, 4:0, 5:0}
        self.threshold = 0.05
        
        # TODO (Ex. 9c): Lines for cartesian velocity commands and gripper commands Publishers 
        self.cartesian_velocity_pub = rospy.Publisher('cartesian_velocity', Float64MultiArray, queue_size=1)
        self.gripper_width_pub = rospy.Publisher('gripper_width', Float64, queue_size=1)
        
        
        # TODO (Ex. 9e): Lines for the declaration of the message for the 
        # Publisher of the cartesian velocity commands and for the declaration of the 
        # message for the Publisher of the gripper width
        
        
        # TODO (Ex. 9d): Lines for the Subscriber to the mapped gripper force 
        self.force_mapped_sub = rospy.Subscriber("force_mapped", Float64, self.force_mapped_callback)


    def force_mapped_callback(self, msg):
        self.mapped_force = msg.data
        
    def normalize_analog_inputs(self, analog_value):
        """
        Normalize-function: 
        Creating a zero-zone in the center of the analog sticks to avoid drift.
        Size of the zero-zone defined with the threshold value.
        """
        if abs(analog_value) <= self.threshold:
            normalized_value = 0.0
        elif analog_value > self.threshold:
            normalized_value = analog_value - self.threshold
        elif analog_value < -self.threshold:
            normalized_value = analog_value + self.threshold
        return normalized_value


    def run(self):
        pygame.init()
        joysticks = []
        
        print(pygame.joystick.get_count())
        for i in range(pygame.joystick.get_count()):
            joysticks.append(pygame.joystick.Joystick(i))
            print(joysticks)
        for joystick in joysticks:
            joystick.init()
        
        stop = False
        cartesian_velocity_msg = Float64MultiArray()
        gripper_width_msg = Float64()
        cartesian_velocity_msg.data = self.cartesian_velocity
        # Assigning variables to the gripper message
        gripper_width_msg.data = self.gripper_width
        rate = rospy.Rate(self.rate)

        while not stop and not rospy.is_shutdown():

            """
            In this for-loop the controller inputs are handled as events
            with the Pygame library
            """
            for event in pygame.event.get():
                
                # Safing the analog values of the sticks
                if event.type == pygame.JOYAXISMOTION:
                    self.analog_keys[event.axis] = event.value
                    
                # Setting bool variables if button is pressed
                if event.type == pygame.JOYBUTTONDOWN:
                    # Square-Button
                    if event.button == 3:
                        stop = True
                    # X-Button
                    if event.button == 0:
                        self.open_gripper = True
                    # O-Button
                    if event.button == 1:
                        self.close_gripper = True
                    # Triangle-Button
                    if event.button == 2:
                        if self.angular == True:
                            self.angular = False
                        else:
                            self.angular = True

                # Setting bool variables if button is released
                if event.type == pygame.JOYBUTTONUP:
                    # X-Button
                    if event.button == 0:
                        self.open_gripper = False
                    # O-Button
                    if event.button == 1:
                        self.close_gripper = False
                        

            """
            TODO (Ex. 8d): Incrementally increase or decrease self.gripper_width when the 
            X-Button or the O-Button is kept pressed
            """
            if self.mapped_force < 0.9: # Limit for gripper force to avoid moving to block
                if self.open_gripper == True:
                    self.gripper_width += self.k_gripper / self.rate 
            if self.close_gripper == True:
                self.gripper_width -= self.k_gripper / self.rate 

            # Check if gripper is already open or closed
            if self.gripper_width > 0.08:
                self.gripper_width = 0.08
            if self.gripper_width < 0.0:
                self.gripper_width = 0.0


            """
            TODO (Ex. 8e,f): Map and scale the analog values from the sticks to the 
            cartesian velocity variable.
            self.analog_keys[0]: x-axis of left stick
            self.analog_keys[1]: y-axis of left stick
            self.analog_keys[3]: x-axis of right stick
            self.analog_keys[4]: y-axis of right stick
            """
            if self.angular == False:
                self.cartesian_velocity[0] = self.analog_keys[0] * self.k_trans
                self.cartesian_velocity[1] = self.analog_keys[1] * self.k_trans
                self.cartesian_velocity[2] = self.analog_keys[4] * self.k_trans
                self.cartesian_velocity[3] = 0
                self.cartesian_velocity[4] = 0
                self.cartesian_velocity[5] = 0

            elif self.angular == True:
                self.cartesian_velocity[0] = 0
                self.cartesian_velocity[1] = 0
                self.cartesian_velocity[2] = 0
                self.cartesian_velocity[3] = self.analog_keys[0] * self.k_rot
                self.cartesian_velocity[4] = self.analog_keys[1] * self.k_rot
                self.cartesian_velocity[5] = self.analog_keys[4] * self.k_rot


            # Avoid drift in the center of the analog sticks
            for i in range(len(self.cartesian_velocity)):
                self.cartesian_velocity[i] = self.normalize_analog_inputs(self.cartesian_velocity[i])
                
#                
            """
            TODO (Ex. 8g): Test the script
            """
            print(self.gripper_width)
            print(self.cartesian_velocity)



            

            time.sleep(1/self.rate)
            
            # TODO (Ex. 9f):
            # Line for the ROS loop in the run() function
            # TODO (Ex. 9g):
            # Assgingin the values to the cartesian velocity message
            cartesian_velocity_msg.data = self.cartesian_velocity
            # Assigning variables to the gripper message
            gripper_width_msg.data = self.gripper_width
            self.cartesian_velocity_pub.publish(cartesian_velocity_msg)
            self.gripper_width_pub.publish(gripper_width_msg)
                        # Gamepad: Vibrate according to gripper force, when threshold is reached
            if self.mapped_force > 0.5:
                rumble_strength = self.mapped_force - 0.5
            else:
                rumble_strength = 0.0
                
            joystick.rumble(rumble_strength, rumble_strength, 0)

            rate.sleep()



if __name__ == '__main__':
   # TODO (Ex. 9b): Line to initialize the ROS Node
    rospy.init_node('teleoperation', anonymous=False)
    n = Node()
    n.run()
