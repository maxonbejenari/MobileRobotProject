#  Mobile Robot Project
<img width="1867" height="890" alt="Screenshot from 2025-11-23 23-17-05" src="https://github.com/user-attachments/assets/9af8f11e-a784-4e94-9116-e6c62aa82d28" />

This project focuses on developing a mobile robot with a complete workflow from CAD design to real-time sensor data processing.

##  CAD to URDF Conversion

The robot model was designed in CAD and exported to URDF using the `onshape_to_robot` library. This allowed the robot to be easily imported into ROS for simulation and development, maintaining accurate links, joints, and physical properties.

### Install

1) Asign material on all Parts of your Robot
2) Create python3 enviroment
  ```bash
  python3 -m venv your-env-name
  ```
3) Activate your enviroment
  ```bash
  source your-env-name/bin/activate
  ```
4) Install onshape-to-robot library
  ```bash
  pip install onshape-to-robot
  ```


<img width="1867" height="1041" alt="Screenshot from 2025-11-23 23-18-12" src="https://github.com/user-attachments/assets/c4c2b0b1-36b0-4713-8f3c-4e00dd877f49" />


##  Gazebo Simulation

The robot was successfully spawned in **Gazebo**, allowing for real-time simulation and testing of sensor data and navigation in a virtual environment.

##  LIDAR Integration

A LIDAR sensor was added to the robot to provide distance measurements from the environment. A custom ROS node was written to:

- Receive raw LIDAR scan data  
- Compute and publish the distance to detected obstacles (in meters)  
- Make the information available for further navigation or mapping modules

<img width="1867" height="1041" alt="Screenshot from 2025-11-23 23-29-58" src="https://github.com/user-attachments/assets/94cdd607-9c7b-47a6-a698-cbdeaaf4c47e" />

##  Goals

The project aims to create a functional base for a mobile robot capable of:

- Reading simulation-world sensor data  
- Reacting to obstacles  
- Being expanded with future navigation, SLAM, and control components

## License
MIT
