# turtle-experiment
Undergraduate Research files for robotic-turtle experiments in MIT's Distributed Robotics Laboratory. 
While working on a project in the Distributed Robotics Laboratory at MIT’s Computer Science & Artificial Intelligence Laboratory (CSAIL), I was tasked with developing ROS 2 code to simultaneously collect data from a ROBOTous 6-axis force-torque sensor and 3 Dynamixel motors. The challenge stemmed from the fact that the existing demo code for the sensor was written in C++ for ROS 1 Kinetic, but the project required using ROS 2. Collecting data from these hardware components would enable our team to perform experiments investigating how different materials affect the control dynamics of a robotic sea turtle flipper.

I had to thoroughly understand how USB communication packets were used to transmit commands, set parameters, and read responses between the force-torque sensor and the Linux OS. Additionally, I had to adapt this for ROS 2’s node structure, which involved converting key parts of the code from C++ to Python and ensuring smooth communication between the hardware and software layers.

A major hurdle was integrating the sensor’s C++ code with the motors’ Python API in a ROS 2 environment, which required managing data synchronization across different languages and communication protocols. Through extensive debugging and modification of the node structures, I successfully integrated the inputs and outputs in a stable and efficient manner, allowing real-time data collection from both the sensor and motors.

I no longer have access to the Force/Torque sensor or robotic flipper, so these instructions are from my notebook.

---

**Building packages** \
Always build packages in one terminal, source and run in a seperate terminal. \
Open Terminal, navigate to ros2_ws. Make sure that conda is deactivated prior to building using conda info --envs. If conda is activated, you will want to run conda deactivate. This is to prevent issues where python libraries for humble are different from system python environments, as referenced in https://github.com/ros2/examples/issues/303#issuecomment-1734590774. Now you can build regularly using colcon build.

---

**Pulling data from Force/Torque Sensor** \
Cd to ros2_ws/ and run ```$source install/setup.bash``` \
Check USB port using ls /dev/ttyUSB*. Make sure correct USB port is referenced in rft_sensor_serial. It is listed as a param so you can set it by calling rosparam set. \
Start the node using ros2 run rft_sensor_serial main \
In a seperate terminal, run ```$rqt```. Pull of the service caller plugin.
- Set the op_type to 11 and call to run the sensor. \
- Set the op_type to 12 to stop the sensor.
- There are more commands available. You can look at the code and see that it's possible to obtain sensor information like baudrate, port, and sensor model.
In the rqt window, you can pull up a plot of the force/torque. Topics are wrench_data/wrench/force and wrench_data/wrench/force.

---

**Setting Data to Dynamixel: Documentation from Dynamixel** \
Also need to make sure that the USB port is correct using the same method.
Open terminal #1
```$ ros2 run dynamixel_sdk_examples read_write_node```

---

**Open terminal #2 (run one of below commands at a time)** \
```$ ros2 topic pub -1 /set_position dynamixel_sdk_custom_interfaces/SetPosition "{id: 1, position: 1000}" ``` \
```$ ros2 service call /get_position dynamixel_sdk_custom_interfaces/srv/GetPosition "id: 1"```
