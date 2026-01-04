#!/usr/bin/env python3

import rospy
import actionlib
from franka_gripper.msg import MoveGoal, MoveAction
from std_msgs.msg import Float64


class Node(object):

    def __init__(self):
        # Variables
        self.gripper_width = 0.08
        self.gripper_speed = 0.1

        # Create the gripper action client
        self.client = actionlib.SimpleActionClient('/franka_gripper/move', MoveAction)

        # Wait until the action server has started up and started listening for goals
        self.client.wait_for_server()

        # Initialise subscribers
        self.gripper_sub = rospy.Subscriber('gripper_width', Float64, self.command_callback, queue_size=1)
        
        # Open Gripper
        self.goal = MoveGoal(width = self.gripper_width, speed = self.gripper_speed)
        self.client.send_goal(self.goal)


    def command_callback(self, msg):
        """
        Callback to get the desired gripper width
        """
        self.gripper_width = msg.data

        # Go to gripper position
        self.goal = MoveGoal(width = self.gripper_width, speed = self.gripper_speed)
        self.client.send_goal(self.goal)


    def run(self):
        rospy.spin()


if __name__ == '__main__':
    rospy.init_node('gripper_manager', anonymous=True)
    n = Node()
    n.run()
