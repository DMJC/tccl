# TCCL
Thrustmaster Configuration Control for Linux
- A Linux reimplementation of TARGET focusing on the HOTAS Warthog Joystick
- Frontend Code is written in GTKMM/C++ and is based on wejoy. https://github.com/Vantskruv/wejoy
---
How to Use:
- TLLC will detect Thrustmaster devices connected to your PC.
- Select the devices you wish to combine into a virtual joystick and click create profile.
- Configure Axes and Button Mappings (Not yet implemented)
- Save/Render to file which will generate a .lua script.
- Run with wejoy (an application status icon will eventually be provided that wraps wejoy for you for easy use).
- TLLC will output .lua files which can be loaded using wejoy. Eventually I plan to integrate launching wejoy with a selected profile into the application making it a one stop shop.
---
Caveats/Issues
Device ordering is based on libudev enumeration. This can be somewhat affected by swapping devices around USB ports and is purely cosmetic. It has no bearing on the operation of the binding.
---
Screenshots:
![TCCL Main Page](https://user-images.githubusercontent.com/732515/204790875-c5a0cb54-1264-4bbf-b3aa-ae9f81ffe217.png)
![TCCL Axis Binding](https://user-images.githubusercontent.com/732515/204790898-1c7096c5-57ab-4e00-bc7d-0caf2e6917e9.png)
---
Future:
- I own a Thrustmaster T-Flight Rudder in addition to my Pendular Rudder, I will at some point implement support for this, I suspect it will be essentially the same code as the Pendular rudder.
- Cougar Flightstick Support. I have one and at some point it will be added, preliminary support exists.
- Cougar MFD support, I don't own a Cougar MFD pack so I am only detecting MFD1 and MFD2 based on ID. I haven't put time/effort into making the Cougar MFD work.
