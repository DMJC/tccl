#include "axes_window.h"
#include <iostream>
#include <libudev.h>

Axes_Window::Axes_Window()
{
  set_title("TCCL - AXIS Mapping");
  set_border_width(10);
  add(w_box);

        std::string name = "button";
        std::map<std::string, Device_Box*> all_buttons;

		Device_Box *dev_box = new Device_Box(name, devmodel_img);
		all_buttons[name] = dev_box;
		i--;
		w_box.add(*dev_box);
  w_box.show_all();
}

Axes_Window::~Axes_Window()
{
}
