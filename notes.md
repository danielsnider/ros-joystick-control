git clone https://github.com/mincrmatt12/ros-joystick-control.git
cd ~/ros-joystick-control/arduino/
pio init --board megaatmega2560
nano platformio.ini 
curl https://raw.githubusercontent.com/platformio/platformio/develop/scripts/99-platformio-udev.rules  > /etc/udev/rules.d/99-platformio-udev.rules
# After this file is installed, physically unplug and reconnect your board.
sudo service udev restart
pio run -t upload
cd ~/ros-joystick-control/
source devel/setup.bash


# start a stream of commands
rostopic  pub -r10 /arm_controller/command trajectory_msgs/JointTrajectory '{joint_names:  ["hip", "shoulder", "elbow",  "wrist"], points: [{positions:  [0.1, -0.5, 0.5,  0.75],  tim
e_from_start:  [1.0, 0.0]}]}'

# monitor the commands
rostopic echo /arm_controller/command

roslaunch launcher.launch

# output should be
[INFO] [1487354908.155966, 7398.368000]: msg received
[INFO] [1487354908.162019, 7398.370000]: msg.points = 1
[INFO] [1487354908.180214, 7398.373000]: msg.joint_names[0] = hip
[INFO] [1487354908.194747, 7398.377000]: msg.points[0].positions_length = 4
[INFO] [1487354908.206841, 7398.382000]: points[0].positions[0] =  0.10
[INFO] [1487354908.220732, 7398.391000]: points[0].positions[1] = -0.50
[INFO] [1487354908.233679, 7398.396000]: points[0].positions[2] =  0.50
[INFO] [1487354908.237420, 7398.400000]: points[0].positions[3] =  0.75

# edit code and relaunch

pio run -t upload && roslaunch ../launcher.launch