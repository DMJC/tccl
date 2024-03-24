#include "joy_button_box.h"
#include <iostream>
#include <libudev.h>

Joy_Button_Box::Joy_Button_Box()
{
}

Joy_Button_Box::Joy_Button_Box(vector<vector<string>> joy_button, string image, string device, string device_name, int device_num) : Joy_Button_Box()
{
    add(joy_button_box);
    this->joy_button_box.add(v_box);
    this->v_box.set_property("orientation", Gtk::ORIENTATION_VERTICAL);
    device_name = device_name + " Button Bindings";
    this->device_label.set_text(device_name);
    this->device_label.set_halign(Gtk::ALIGN_CENTER);
    this->v_box.add(device_label);
    this->v_box.add(h_box);
    this->h_box.add(i_fixed);
    this->i_fixed.put(dev_image,0,0);
    this->dev_image.set(image);
    this->h_box.add(w_box);
    this->w_box.set_property("orientation", Gtk::ORIENTATION_VERTICAL);

    string name = "joy_button";
    std::map<string, Joy_Button*> all_joy_button;
    int size = 0;
    size = joy_button.size();
        for(int i = 0; i < size; i++){
            string name = joy_button[i][1];
            string description = joy_button[i][1];
//	    cout << "name: " << name << " joy_button description: " << description << endl;
	    name = name + ": ";
	    Joy_Button *joy_button_box = new Joy_Button(device_num, name, description);
	    all_joy_button[name] = joy_button_box;
	    w_box.add(*joy_button_box);
        }
    joy_button_box.show_all();
}

Joy_Button_Box::~Joy_Button_Box()
{

}

Gtk::Box* Joy_Button_Box::get_button_boxes()
{
	return &this->w_box;
}
