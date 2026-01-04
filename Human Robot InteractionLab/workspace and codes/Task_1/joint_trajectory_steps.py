#!/usr/bin/env python3

import rospy
import numpy as np
from franka_msgs.msg import FrankaState
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint


def sender():
            
    """
    TODO: Define the goal positions for the seven robot joints (Exercise 14f)
    """
    goal_positions = 


    # Joint Trajectory
    # Number of waypoints in the trajectory
    N_steps = 200

    """
    TODO: Create an N_stepsx7 array for the joint positions along the trajectory.
    To do this, divide the distance between the start and target positions into N equal steps.
    (one way to solve the problem is with np.linspace())
    """
    traj = 
    

    rospy.loginfo("Starting to execute the trajectory!")
    rospy.sleep(1)

    i = 0

    while not rospy.is_shutdown():
        
        if i < N_steps: 
            joint_pos_msg.points[0].positions = traj[i, :]
        else:
            joint_pos_msg.points[0].positions = traj[N_steps-1, :]


        print(joint_pos_msg.points[0].positions)
            
        joint_pos_publisher.publish(joint_pos_msg)

        i = i + 1

        rate.sleep()


if __name__ == '__main__':
    
    rospy.init_node('joint_trajectory', anonymous=False)
    
    # Parameters
    rate = rospy.Rate(10)

    """
    TODO: Initialise a Publisher publishing to the Topic "/position_joint_trajectory_controller/command"
    with the message type "JointTrajectory". Joint positions sent to this topic are used as desired positions 
    for the low level position controller.
    """
    joint_pos_publisher =     
    
    
    # Read the robot states once and get initial joint positions
    franka_state = rospy.wait_for_message("franka_state_controller/franka_states", FrankaState)
    initial_pos = list(franka_state.q)

    # Create the message for commanding the joint positions
    panda_joints = ['panda_joint1','panda_joint2','panda_joint3','panda_joint4','panda_joint5',
                         'panda_joint6','panda_joint7']
    joint_pos_msg = JointTrajectory()
    joint_pos_msg.joint_names = panda_joints
    joint_pos_msg.points.append(JointTrajectoryPoint())
    joint_pos_msg.points[0].positions = initial_pos
    joint_pos_msg.points[0].velocities = [0.0 for i in panda_joints]
    joint_pos_msg.points[0].accelerations = [0.0 for i in panda_joints]
    joint_pos_msg.points[0].time_from_start = rospy.Duration(3)

    sender()
