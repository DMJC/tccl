-- profile name
-- profile description goes in here
devices =
   {

   }
-- Virtual devices 
v_devices =
   {
      v0 =
         {
            buttons = 51,
            axes = 14
         }
   }

-- Trigger
function d0_b1_event(value)
   if value == 1 then
      send_button_event(0, 1, 1)
   else
      send_button_event(0, 1, 0)
   end
end

-- Weapon Release
function d0_b3_event(value)
   if value == 1 then
      send_button_event(0, 3, 1)
   else
      send_button_event(0, 3, 0)
   end
end

-- X-axis
function d0_a0_event(-value)
      send_axis_event(0, 1, value)
end

-- Y-axis
function d0_a1_event(value)
      send_axis_event(0, 2, value)
end

