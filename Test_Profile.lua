Starting to Save Profile
--Profile Name: Test Profile
--Created by TCCL
--Physical devices to use (type lsusb in terminal to list your connected devices)
devices=
   {
        d0 = --Thrustmaster HOTAS Warthog
         {
            vendorid = 0x044f
            productid = 0x0402
         },

        d1 = --Thrustmaster HOTAS Warthog Throttle
         {
            vendorid = 0x044f
            productid = 0x0404
         },

        d2 = --Thrustmaster Pendular Rudder Pedals
         {
            vendorid = 0x044f
            productid = 0xb68f
         },

        kbd0 = "/dev/input/event0",--keyboard device try finding a suitable device with ls /dev/input/by-id
    }
--Virtual Devices to Create
v_devices =
   {
      v0 =
         {
            buttons = 51,
            axes = 14
         }
   }
--axis bindings

--X-Axis: 
--Axis Binding has not been set

--Y-Axis: 
--Axis Binding has not been set

--Trim Hat-Left/Right: 
--Axis Binding has not been set

--Trim Hat-Up/Down: 
--Axis Binding has not been set

--Slew Control Left/Right: 
--Axis Binding has not been set

--Slew Control Up/Down: 
--Axis Binding has not been set

--Right Throttle: 
--Axis Binding has not been set

--Left Throttle: 
--Axis Binding has not been set

--Incr/Decr: 
--Axis Binding has not been set

--Coolie-Left/Right: 
--Axis Binding has not been set

--Coolie-Up/Down: 
--Axis Binding has not been set

--Right toe Brake: 
--Axis Binding has not been set

--Left toe Brake: 
--Axis Binding has not been set

--Rudder: 
--Axis Binding has not been set

--button mappings

--Gun Trigger 1st Stage: 
--Button Binding has not been set

--Weapon Release: 
--Button Binding has not been set

--Nosewheel: 
--Button Binding has not been set

--Pinky Switch: 
--Button Binding has not been set

--Master Mode: 
--Button Binding has not been set

--Gun Trigger 2nd Stage: 
--Button Binding has not been set

--TMS Up: 
--Button Binding has not been set

--TMS Right: 
--Button Binding has not been set

--TMS Down: 
--Button Binding has not been set

--TMS Left: 
--Button Binding has not been set

--DMS Up: 
--Button Binding has not been set

--DMS Right: 
--Button Binding has not been set

--DMS Down: 
--Button Binding has not been set

--DMS Left: 
--Button Binding has not been set

--CMS Forward: 
--Button Binding has not been set

--CMS Right: 
--Button Binding has not been set

--CMS Backwards: 
--Button Binding has not been set

--CMS Left: 
--Button Binding has not been set

--CMS Push: 
--Button Binding has not been set

--Coolie In: 
--Button Binding has not been set

--Right Thumb In: 
--Button Binding has not been set

--Right Thumb Hat-Up: 
--Button Binding has not been set

--Right Thumb Hat-Forward: 
--Button Binding has not been set

--Right Thumb Hat-Down: 
--Button Binding has not been set

--Right Thumb Hat-Back: 
--Button Binding has not been set

--Speed Brake Forwards: 
--Button Binding has not been set

--Speed Brake Backwards: 
--Button Binding has not been set

--Boat Switch Forwards: 
--Button Binding has not been set

--Boat Switch Backwards: 
--Button Binding has not been set

--China Hat Forwards: 
--Button Binding has not been set

--China Hat Backwards: 
--Button Binding has not been set

--Pinky Switch Forwards: 
--Button Binding has not been set

--Pinky Switch Backwards: 
--Button Binding has not been set

--Left Throttle Button: 
--Button Binding has not been set

--Engine Flow L Override: 
--Button Binding has not been set

--Engine Flow R Override: 
--Button Binding has not been set

--Left Engine Operate Backwards: 
--Button Binding has not been set

--Right Engine Operate Backwards: 
--Button Binding has not been set

--APU START: 
--Button Binding has not been set

--L/G WRN: 
--Button Binding has not been set

--FLAPS UP: 
--Button Binding has not been set

--FLAPS DN: 
--Button Binding has not been set

--EAC ARM: 
--Button Binding has not been set

--RDR ALTM NRM: 
--Button Binding has not been set

--AUTOPILOT ENGAGE/DISENGAGE: 
--Button Binding has not been set

--PATH: 
--Button Binding has not been set

--ALT: 
--Button Binding has not been set

--Unknown: 
--Button Binding has not been set

--Unknown: 
--Button Binding has not been set

--Left Engine Operate Forwards: 
--Button Binding has not been set

--Right Engine Operate Forwards: 
--Button Binding has not been set

--End of Bindings
