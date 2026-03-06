# SYNOPSIS OF THE REPOSITORY

**REPOSITORY OBJECTIVE** - Humanoid(Unitree G1) possession of Humanlike Behaviour for Successful Manipulation Of Objects with the latest LTS Software Stack For Deployment

**REPOSITORY STRATEGY** - COMBINED USE OF REINFORCEMENT LEARNING AND BEYONDMIMIC (FOR HUMANLIKE GAIT FORMULATION AND FORMATION)

The repository is in the sole discretion of Mr. Velayudhan Aravindakshan and are welcome to code reviews, updates and modification or suggestions from developers. 

***Disclaimer : I am not planning to reinvent the wheel but make the wheel more efficient***

## APPROACH STRATEGY and PLAN
**ALL VIRTUAL FIRST** approach with the verification of RL and beyondmimic simulation completion(subject to hardware bottlenecks) and hardware deployment and testing(subject to hardware availability)

### 1. DIGITAL TWIN (STATUS - DONE)
Building the robot (Unitree G1) with the use of existing STL files.

### 2. RVIZ VISUALIZATION (NON PHYSICS TRANSFORMATION AND MESSAGE EXCHANGE) (STATUS - DONE)
Visualization of the robot with correct mesh rendering from the urdf file

### 3. RVIZ LOCOMOTION (STATUS - DONE)
Robot movement on the virtual world (without physics) using joystick model control

### 4. MuJoCo VISUALIZATION - PHYSICS ENGINE (STATUS - DONE)
Robot visualization with the robot in the capacity to self balance and stand.

### 5. MuJoCo LOCOMOTION (STATUS - IN PROGRESS)
Robot movement with the influence of world factors like gravity, friction etc and by using joystick model control

### 6. MuJoCo CONTROL (STATUS - PLANNED)
Robot manipulation with the use of camera for pick and place of an object

### 7. REINFORCEMENT LEARNING and BEYONDMIMIC (STATUS - PLANNED)
Robot gait mirroring with respect to real human gait movement by training with the use of RL and BEYONDMIMIC

### 8. INTEGRATION (STATUS - PLANNED)
Encapsulation of above modular functionalities to make the robot<br><br>
***a. Move in an virtual environment with object avoidance based on command<br>
b. Traverse from a point A to point B and to point C <br>
c. Object manipulation to be done in point B.***

### 9. DATA COLLECTION AND ANALYSIS (STATUS - PLANNED)
Taking out the relevant data to be compared when deployed with real hardware

### 10. HARDWARE DEPLOYMENT AND TESTING (STATUS - ON HOLD)
Test the package in the real hardware for the testing and date analysis for further improvement

## PACKAGE LIST
| Package name | Brief |
| :----: | :----: |
|unitree_g1_description|meshes, urdf and visual aspects related to the robot|
|unitree_g1_rviz|Non Physics related simulation of the robot|
|unitree_g1_mujoco|Physics related simulation of the robot|




