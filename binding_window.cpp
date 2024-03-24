#include "binding_window.h"


Binding_Window::Binding_Window()
{
  set_title("TCCL - AXIS/BUTTON Mapping");
  set_border_width(10);
  add(binding_box);
  this->binding_scrolled_box.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  this->binding_scrolled_box.set_propagate_natural_width(TRUE);
  this->binding_scrolled_box.set_propagate_natural_height(TRUE);
  this->binding_scrolled_box.set_vexpand(TRUE);
  this->binding_scrolled_box.set_hexpand(TRUE);
  this->binding_box.add(binding_scrolled_box);
  this->save_button.set_label("Save Profile");
  this->close_button.set_label("Close Profile");
  save_button.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Binding_Window::on_save_button_clicked), "button 1"));
  close_button.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Binding_Window::on_close_button_clicked), "button 1"));
}

Binding_Window::~Binding_Window()
{
}

void Binding_Window::set_active_devices(vector<string> active_devices)
{
	this->active_devids = active_devices;
}

vector<string>Binding_Window::get_active_devices(void)
{
	return this->active_devids;
}

void Binding_Window::set_active_models(vector<string> active_models)
{
	this->active_models = active_models;
}

vector<string>Binding_Window::get_active_models(void)
{
	return this->active_models;
}

void Binding_Window::on_close_button_clicked(const Glib::ustring& data)
{
	
}

void Binding_Window::on_save_button_clicked(const Glib::ustring& data)
{
	cout << "Starting to Save Profile" << endl;
	cout << "--Profile Name: " << this->profile_name_entry.get_text() << endl;
	cout << "--Created by TCCL" << endl;
	cout << "--Physical devices to use (type lsusb in terminal to list your connected devices)" << endl;
	cout << "devices=\n   {" << endl;
	int count = 0;
	auto it1 = active_devids.begin(); 
	auto it2 = active_models.begin();
    for ( it1 != active_devids.end(); it2 != active_models.end(); ++it1, ++it2) {  
        string mod_id = *it1;
        string dev_id = *it2;  
        // Process the element         
		cout << "        d"<< count << " = --" << dev_id << "\n         {" << endl;
		cout << "            vendorid = 0x" << "044f" << "\n            productid = 0x" << mod_id << "\n         },\n" << endl;
		count ++;
    }
	cout << "        kbd0 = \"/dev/input/event0\"," << "--keyboard device try finding a suitable device with ls /dev/input/by-id" << endl;
	cout << "    }" << endl;   
    cout << "--Virtual Devices to Create" << endl;
    cout <<"v_devices =\n   {\n      v0 =\n         {\n" << "            buttons = " << this->buttons << ",\n" << "            axes = " << this->axes << endl;

    cout <<"         }\n   }\n" << "--axis bindings\n" << endl;

    // Retrieve text values from Gtk::Label items
	int itd = 0;
	int itb = 0;
    for (const auto& child : (*this->ab_box_ref).get_children()) 
	{
        auto axis_box = dynamic_cast<Axis_Box*>(child);
        if (axis_box) 
		{
			Gtk::Box* axisBox = axis_box->get_axis_boxes();
   			for (const auto& child : (*axisBox).get_children()) 
			{
				auto axis_box = dynamic_cast<Axis*>(child);
        		if (axis_box)
				{
					cout << "--" << (*axis_box).get_name() << endl;
					cout << "function " << "d" << itd << "_a" << itb << "_event(value)" << endl;
					cout << "\tsend_axis_event("<< ", value)" << endl;
					cout << "end" << endl;
					itb++;
				}
			}
		itd++;
        }
    }

/*    cout << "--" << "AXIS Name" << endl;
	cout << "function d1_a3_event(value)" << endl;
	cout << "      send_axis_event(0, 3, value)" << endl;
	cout << "end" << endl;*/

	cout << "--button mappings\n" << endl;
	itd = 0;
	itb = 0;
    for (const auto& child : (*this->ab_box_ref).get_children()) 
	{
        auto joy_button_box = dynamic_cast<Joy_Button_Box*>(child);
        if (joy_button_box) 
		{
			Gtk::Box* buttonBox = joy_button_box->get_button_boxes();
   			for (const auto& child : (*buttonBox).get_children()) 
			{
				auto but_box = dynamic_cast<Joy_Button*>(child);
        		if (but_box)
				{
					cout << "--" << (*but_box).get_name() << endl;
					cout << "function d" << itd << "_b" << itb << "_event(value)" << endl;
					cout << "end" << endl;
					itb++;
				}
			}	
		itd++;		
        }
    }
    cout << "--End of Bindings" << endl;
}
