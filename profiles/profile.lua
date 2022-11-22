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

-- X-axis
function d0_a1_event(-value)
      send_axis_event(0, 1, value)
end

-- Y-axis
function d1_a1_event(value)
      send_axis_event(0, 2, value)
end

