# Unitree G1 & Robotics Development Guide

This repository in ownership of **Mr. Velayudhan Aravindakshan** contains the implementation, simulation setup, and troubleshooting workflows for the Unitree G1 humanoid and general ROS 2 robotic systems.

## Table of Contents

* [Unitree G1 and Robotics Setup](#unitree-g1-and-robotics-setup)
* [Walking Strategy and Control](#walking-strategy-and-control)
* [Simulation Environments](#simulation-environments)
* [Troubleshooting and System Fixes](#troubleshooting-and-system-fixes)

---

## Unitree G1 and Robotics Setup

### Core Dependencies
To process robot models and coordinate transforms, the following dependencies are required:
* **robot_state_publisher**: Reads the URDF file and outputs the coordinate transform (TF).
* **joint_state_publisher_gui**: Used to visualize the model and manually move the limbs.
* **Package Requirements**: Requires `ros-jazzy-xacro`, `ros-jazzy-robot-state-publisher`, and `ros-jazzy-joint-state-publisher-gui`.

### URDF Visualization
To visualize the robot in RViz 2 manually:
1. Navigate to the folder containing the URDF.
2. Run the joint state publisher: `ros2 run joint_state_publisher_gui joint_state_publisher_gui <path-to-urdf>`.
3. In a second terminal, run the robot state publisher using xacro to process the description: `ros2 run robot_state_publisher robot_state_publisher --ros-args -p robot_description:="$(xacro <path-to-urdf>)"`.
4. Launch **RViz 2** and set the fixed frame to the **base_link**.

---

## Walking Strategy and Control
* **Walking Logic**: The robot walks when its root link moves relative to a global fixed frame like `odom` or `map`.
* **Virtual Odometry**: A node listens for velocity commands, calculates the new position, and broadcasts the TF transform.
* **Teleoperation**: Movement can be controlled via keyboard using:
  `ros2 run teleop_twist_keyboard teleop_twist_keyboard`.

---

## Simulation Environments

### Unity Integration
Unity is used for handling physics, gravity, and collisions.
* **Communication**: Requires the `Unity-ROS 2 Bridge` and `ROS-TCP-Connector`.
* **TCP Endpoint**: Run the TCP connector node to allow ROS 2 communication: `ros2 run ros_tcp_endpoint default_server_endpoint --ros-args -p ROS_IP:=127.0.0.1`.
* **URDF Import**: Assets and meshes are imported into Unity using the **URDF Importer** package.

### MuJoCo Integration
Due to system limitations with Unity, MuJoCo is utilized for Python-based physics simulation.
* **Virtual Environment**: Setup using `python3 -m venv gl-env` and install `mujoco` and `numpy`.
* **Compatibility**: The URDF must be modified for MuJoCo by adding the XML version header and defining the mesh directory.
* **Loading**: Models can be viewed using:
  `python3 -m mujoco.viewer --mjcf=<path-to-urdf>`.

---

## Troubleshooting and System Fixes
* **Drive Mounting**: If a forced restart causes an external drive volume to become non-parsable, fix the NTFS partition using: `sudo ntfsfix -d /dev/sda1`.
* **Virtual Box**: To enable screen resizing, install `build-essential`, `dkms`, and `linux-headers`.
* **Debugging**: To check for URDF loading faults, use the MuJoCo Python API to import the model directly from the XML path:
  `python3 -c "import mujoco; mujoco.MjModel.from_xml_path('<path-to-urdf>')"`.