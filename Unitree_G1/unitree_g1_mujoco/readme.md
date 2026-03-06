# **unitree_g1_mujoco repository** -  Physics related simulation of the robot
This repository deals with the Physics related simulation of the robot(Unitree G1) with the use of Physics engine MuJoCo.

MuJoCo being a physics engine with python dependency creating of python virtual environment is vital

# Virtual Environment - creation and configuration and commands used

#Navigate to your workspace<br>
*cd ~/xyz/workspace*<br>

#Create the virtual environment<br>
*python3 -m venv venv_mujoco*<br>

#Activate the environment<br>
*source venv_mujoco/bin/activate*<br>

#Install required packages<br>
*pip install --upgrade pip*<br>
*pip install mujoco numpy*<br>

# Visualization of the robot in Mujoco (Physics Engine)<br>

Python file that uses the native MuJoCo viewer enables to inspect the robot's geometry, joint axes, and frames.

*python3 ~/path_to_python_file/visualize_g1.py*

# Standing and Balancing<br>

The free-fall of the robot due to the influence of gravity. Implementation of PD controller would make the robot stand and balance itself.<br>

*python3 ~/path_to_script/stand_g1.py*

The reponses observed included with tuning factors are :  <br>

a. The robot snapped to an upright position and "shiver" slightly.<br>

b. Immediate falling over immediately - increase KP to stabilise.<br>

c. High vibration violently or explodes - decrease KP or increase KD.<br>

Quick Insight - The robot stance is like a statue and no active compensation is considered at this point. The robot is like a statue and a slight push or pull may result in unstabilty and collapse. Fine tuning of the parameters can be further done however it seems to be irrelavant as reinforcement learning should be applied in the further stages

