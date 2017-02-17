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
roslaunch launcher.launch
