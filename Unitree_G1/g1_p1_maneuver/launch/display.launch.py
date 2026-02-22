import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, Command, PathJoinSubstitution
from launch_ros.actions import Node

def generate_launch_description():
    pkg_path = get_package_share_directory('g1_p1_maneuver')
    
    # 1. Define the 'model' argument with strict choices
    model_arg = DeclareLaunchArgument(
        'model',
        default_value='29dof', # The basic standard is usually the default
        choices=['23dof', '29dof'],
        description='Choose G1 variant: 23dof (Standard) or 29dof (Advanced)'
    )

    # 2. Dynamically build the URDF filename based on the argument
    # If model:=23dof, it looks for g1_23dof.urdf
    # If model:=29dof, it looks for g1_29dof.urdf
    model_config = LaunchConfiguration('model')
    urdf_filename = [ 'g1_', model_config, '.urdf' ]
    urdf_path = PathJoinSubstitution([pkg_path, 'urdf', urdf_filename])

    # 3. Robot State Publisher Node
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': Command(['xacro ', urdf_path])}]
    )

    # 4. Joint State Publisher GUI (Sliders will update automatically)
    joint_state_publisher_gui = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui'
    )

    # 5. RViz Node
    rviz2 = Node(
        package='rviz2',
        executable='rviz2',
        arguments=['-d', os.path.join(pkg_path, 'rviz', 'g1_view.rviz')]
    )

    return LaunchDescription([
        model_arg,
        robot_state_publisher,
        joint_state_publisher_gui,
        rviz2
    ])