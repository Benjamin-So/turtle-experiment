# turtle-experiment
Undergraduate Research files for robotic-turtle experiments in MIT's Distributed Robotics Laboratory. 
I wrote python and c++ code to interface 6-axis Robotous Force/Torque Sensor and Dynamixel Actuated turtle flipper. The c++ code for the force torque sensor was updated to ROS2.

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
