#include "axis_box.h"
#include <iostream>
#include <libudev.h>

Axis_Box::Axis_Box()
{
}

Axis_Box::Axis_Box(vector<vector<string>> axes, string image, string device, string device_name, int device_num) : Axis_Box()
{
    add(axis_box);
    this->axis_box.add(v_box);
    this->v_box.set_property("orientation", Gtk::ORIENTATION_VERTICAL);
    device_name = device_name + " Axis Bindings";
    this->device_label.set_text(device_name);
    this->device_label.set_halign(Gtk::ALIGN_CENTER);
    this->v_box.add(device_label);
    this->v_box.add(h_box);
    this->h_box.add(i_fixed);
    this->i_fixed.put(dev_image,0,0);
    this->dev_image.set(image);
    this->h_box.add(w_box);
    this->w_box.set_property("orientation", Gtk::ORIENTATION_VERTICAL);

    string name = "axis";
    std::map<string, Axis*> all_axes;
    int size = 0;
    size = axes.size();
        for(int i = 0; i < size; i++){
            string name = axes[i][1];
            string description = axes[i][1];
	    name = name + ": ";
	    Axis *axis_box = new Axis(device_num, name, description);
	    all_axes[name] = axis_box;
	    w_box.add(*axis_box);
        }
    axis_box.show_all();
}

Axis_Box::~Axis_Box()
{

}

Gtk::Box* Axis_Box::get_axis_boxes()
{
	return &this->w_box;
}
