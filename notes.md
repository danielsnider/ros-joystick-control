 1192  git clone https://github.com/mincrmatt12/ros-joystick-control.git
 1194  cd ros-joystick-control/
 1196  cd arduino/
 1199  pio init --board megaatmega2560
 1200  pio run
 1201  nano platformio.ini 
 1205  curl https://raw.githubusercontent.com/platformio/platformio/develop/scripts/99-platformio-udev.rules  > /etc/udev/rules.d/99-platformio-udev.rules
 # After this file is installed, physically unplug and reconnect your board.
 1210  sudo service udev restart
 1214  pio run -t upload
dan@ubuntu:~/ros-joystick-control$ roslaunch launcher.launch 
