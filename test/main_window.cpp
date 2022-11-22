#include "main_window.h"
#include <iostream>
#include <libudev.h>

Main_Window::Main_Window()
{
  set_title("Axis");
  set_border_width(10);
  add(w_scrolledwindow);
  this->w_scrolledwindow.add(w_box);
  this->w_scrolledwindow.set_propagate_natural_width(TRUE);
  this->w_scrolledwindow.set_propagate_natural_height(TRUE);
  this->w_box.set_property("orientation", Gtk::ORIENTATION_VERTICAL);

	string axis_list[16][2] = {{"Axis 0","Trigger"},
				  {"Axis 1","Pinkie Switch"},
				  {"Axis 2","Hat Up"},
				  {"Axis 3","Hat Down"},
				  {"Axis 4","Hat Left"},
				  {"Axis 5","Hat Right"},
				  {"Axis 6","TMS Up"},
				  {"Axis 7","TMS Down"},
				  {"Axis 8","TMS Left"},
				  {"Axis 9","TMS Right"},
				  {"Axis 10","Weapon Release"},
				  {"Axis 11","CMS Up"},
				  {"Axis 12","CMS Down"},
				  {"Axis 13","CMS Left"},
				  {"Axis 14","CMS Right"},
				  {"Axis 15","Eject"}};

        std::string name = "axis";
        std::map<std::string, Axis*> all_axes;
	/*Nested for loop for parsing axis list*/
	int size = *(&axis_list + 1) - axis_list;
        for(int i = 0; i < size; i++){
                string name = axis_list[i][0];
                string description = axis_list[i][1];
		cout << "name: " << name << " axis description: " << description << endl;
		name = name + ": ";
		Axis *axis_box = new Axis(name, description);
		all_axes[name] = axis_box;
		w_box.add(*axis_box);
        }
  w_scrolledwindow.show_all();
}

Main_Window::~Main_Window()
{
}
