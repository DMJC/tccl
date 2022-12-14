#include "main_window.h"
#include <iostream>
#include <libudev.h>

Main_Window::Main_Window(){

}

Main_Window::Main_Window(vector<vector<string>> axes)
: Main_Window()
{
  set_title("Axes");
  set_border_width(10);
  add(w_scrolledwindow);
  this->w_scrolledwindow.add(h_box);
  this->h_box.add(dev_image);
  string device = "../images/0402.png";
  this->dev_image.set(device);
  this->h_box.add(w_box);
  this->w_scrolledwindow.set_propagate_natural_width(TRUE);
  this->w_scrolledwindow.set_propagate_natural_height(TRUE);
  this->w_box.set_property("orientation", Gtk::ORIENTATION_VERTICAL);

        std::string name = "axis";
        std::map<std::string, Axis*> all_axes;

        int size = axes.size();
        for(int i = 0; i < size; i++){
                string name = axes[i][0];
                string description = axes[i][1];
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
