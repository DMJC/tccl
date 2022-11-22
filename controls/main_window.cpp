#include "main_window.h"
#include <iostream>
#include <libudev.h>

Main_Window::Main_Window()
{
  set_title("Button");
  set_border_width(10);
  add(w_scrolledwindow);
  this->w_scrolledwindow.add(w_box);
  w_box.set_property("orientation", Gtk::ORIENTATION_VERTICAL);

	string axis_list[16][2] = {{"Joy 0","Trigger"},
				  {"Joy 1","Pinkie Switch"},
				  {"Joy 2","Hat Up"},
				  {"Joy 3","Hat Down"},
				  {"Joy 4","Hat Left"},
				  {"Joy 5","Hat Right"},
				  {"Joy 6","TMS Up"},
				  {"Joy 7","TMS Down"},
				  {"Joy 8","TMS Left"},
				  {"Joy 9","TMS Right"},
				  {"Joy 10","Weapon Release"},
				  {"Joy 11","CMS Up"},
				  {"Joy 12","CMS Down"},
				  {"Joy 13","CMS Left"},
				  {"Joy 14","CMS Right"},
				  {"Joy 15","Eject"}};


        std::string name = "button";
        std::map<std::string, Button*> all_axes;
	/*Nested for loop for parsing axis list*/
	int size = *(&axis_list + 1) - axis_list;
        for(int i = 0; i < size; i++){
                string name = axis_list[i][0];
                string description = axis_list[i][1];
		cout << "name: " << name << " axis description: " << description << endl;
		name = name + ": ";
		Button *axis_box = new Button(name, description);
		all_axes[name] = axis_box;
		w_box.add(*axis_box);
        }
  w_scrolledwindow.show_all();
}

Main_Window::~Main_Window()
{
}
