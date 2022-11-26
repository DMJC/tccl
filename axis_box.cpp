#include "axis_box.h"
#include <iostream>
#include <libudev.h>

Axis_Box::Axis_Box()
{

}

Axis_Box::~Axis_Box()
{

}

Axis_Box::Axis_Box(vector<vector<string>> axes, string image, string device)
: Axis_Box()
{
  add(axis_box);
  this->axis_box.add(h_box);
  this->h_box.add(dev_image);
  string device = "../images/0402.png";
  this->dev_image.set(device);
  this->h_box.add(w_box);
//  this->axis_box.set_propagate_natural_width(TRUE);
//  this->axis_box.set_propagate_natural_height(TRUE);
  this->w_box.set_property("orientation", Gtk::ORIENTATION_VERTICAL);
        std::string name = "axis";
        std::map<std::string, Axis*> all_axes;
	/*Nested for loop for parsing axis list*/
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
  axis_box.show_all();
}
