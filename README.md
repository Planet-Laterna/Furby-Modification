# Furby_modification

Current project is based on 2 really good tutorials [Furby Modification](https://www.instructables.com/Control-a-Furby-with-Arduino-or-other-microcontrol/ "Furby HW Modification") and [Furby Software Basics](https://create.arduino.cc/projecthub/amurison718/furby-hacked-hot-wired-and-channeling-cartman-2de255 "Furby Software Basics"). Please follow first link if you need to perform the hardware modification.

# Scope of this project

This Project is implemented and tested using an Arduino Mega/Uno board, but should work also for ESP32 ones. You would need to change used GPIOs in [Arduino Code](https://github.com/Planet-Laterna/Furby-Modification/blob/main/controller_no_rtos.ino/controller_no_rtos.ino.ino "Controller Code")

Following features are implemented as of now 

- Furby can be controlled by Serial Interface. Refer to [Python Script](https://github.com/Planet-Laterna/Furby-Modification/blob/main/python_scripts/furby_controller.py "Code Send Commands") in order to send a command.

- Furby's mouth movement can be controlled
- Furby's eyes can be controller
- Furby's eyes color can be changed. Some colors are implemented, you can extend this code
- List of availble commnds can be displayed

Following features are in the backlog and not implemented due to time constrains

- Furby Ble control app
- Add Camera to Furby Forehead
- Implement microphone interface for Audio recording
- Implement Speech Syntesis by using availble Speaker
- Reactions to Tongue and Belly pressed
- Laser pointer integration on Furby Forehead
- ...

<h3>Modification - Videos</h3> 

[![Alt text](https://img.youtube.com/vi/D5H40X3DTLs/0.jpg)](https://www.youtube.com/watch?v=D5H40X3DTLs)

[![Alt text](https://img.youtube.com/vi/Y1GI48FS-ZM/0.jpg)](https://www.youtube.com/watch?v=Y1GI48FS-ZM)

# Hardware Modification
Besides modifications described under [Furby Modification](https://www.instructables.com/Control-a-Furby-with-Arduino-or-other-microcontrol/ "Furby HW Modification"), we decided to add some LEDs behind the Furby eyes. For this we used following RGB addressable strip.

[![Alt text](https://img.youtube.com/vi/Fh_xqPpOQJs/0.jpg)](https://www.youtube.com/watch?v=Fh_xqPpOQJs)

# Software Modification
Software Modification logic is described [Furby Software Basics](https://create.arduino.cc/projecthub/amurison718/furby-hacked-hot-wired-and-channeling-cartman-2de255 "Furby Software Basics"). The LEDs strips are controller using the Arduino Neoxipel library ( Do not forget to install it in your environment!).

# Setup Details

- Arduino Mega/UNO or ESP32 (USB C Type) board
- Adapter Board to connect Furby's pins to ESP32 board
- Cables
- Planet Laterna Mini RGB LED strips.
[You can find it](https://de.aliexpress.com/store/1100075030?spm=a2g0o.detail.1000007.1.37f5345aLXupDC "Thin LED Strip")
- Connectors
- Furby's serial controller code. [Arduino Code](https://github.com/Planet-Laterna/Furby-Modification/blob/main/controller_no_rtos.ino/controller_no_rtos.ino.ino "Controller Code")
- PC client Script. [Python Script](https://github.com/Planet-Laterna/Furby-Modification/blob/main/python_scripts/furby_controller.py "Code Send Commands")

This is an open source project, please feel free to add modifications by creating a pull request or fork.

If you like this project, do not buy us a Coffee (  we dont drink Coffee :) ). Just have a look to other projects we are developing and share with friends and colleagues!

We will add features based on our free time... 

You can contact us under:
planet_laterna@outlook.com
or
IG: planetlaterna

Cheers!
