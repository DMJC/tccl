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

    Gtk::FileChooserDialog dialog("Please choose a file",
                                  Gtk::FILE_CHOOSER_ACTION_SAVE);
    // Set up the dialog
//    dialog.set_transient_for(*parent_window); // Optionally set the parent window
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Ok", Gtk::RESPONSE_OK);
    int result = dialog.run();
	// Check the response
    if (result == Gtk::RESPONSE_OK) {
        cout << "File selected: " << dialog.get_filename() << std::endl;
	ofstream output;
	string file = dialog.get_filename();
	output.open(file); // opens the file
    if( !output ) { // file couldn't be opened
       cerr << "Error: profile file could not be opened for writing" << endl;
       exit(1);
    }
	output << "Starting to Save Profile" << endl;
	output << "--Profile Name: " << this->profile_name_entry.get_text() << endl;
	output << "--Created by TCCL" << endl;
	output << "--Physical devices to use (type lsusb in terminal to list your connected devices)" << endl;
	output << "devices=\n   {" << endl;
	int count = 0;
	auto it1 = active_devids.begin(); 
	auto it2 = active_models.begin();
    for ( it1 != active_devids.end(); it2 != active_models.end(); ++it1, ++it2) {  
        string mod_id = *it1;
        string dev_id = *it2;  
        // Process the element         
		output << "        d"<< count << " = --" << dev_id << "\n         {" << endl;
		output << "            vendorid = 0x" << "044f" << "\n            productid = 0x" << mod_id << "\n         },\n" << endl;
		count ++;
    }
	output << "        kbd0 = \"/dev/input/event0\"," << "--keyboard device try finding a suitable device with ls /dev/input/by-id" << endl;
	output << "    }" << endl;   
    output << "--Virtual Devices to Create" << endl;
    output <<"v_devices =\n   {\n      v0 =\n         {\n" << "            buttons = " << this->buttons << ",\n" << "            axes = " << this->axes << endl;

    output <<"         }\n   }\n" << "--axis bindings\n" << endl;

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
				auto axis = dynamic_cast<Axis*>(child);
        		if (axis)
				{
					output << "--" << (*axis).get_name() << endl;
					if ((*axis).get_value() == "None")	
					{
						output << "--Axis Binding has not been set\n" << endl;
					} else {
						output << "function " << "d" << itd << "_a" << itb << "_event(value)" << endl;
						if ((*axis).get_inverted() == 1)
						{
							output << "\tsend_axis_event(0, " << (*axis).get_value() << ", -value)" << endl;
						} else {
							output << "\tsend_axis_event(0, " << (*axis).get_value() << ", value)" << endl;
						}
						output << "end" << endl;
					}
					itb++;
				}
			}
		itd++;
        }
    }

	output << "--button mappings\n" << endl;
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
				auto button = dynamic_cast<Joy_Button*>(child);
        		if (button)
				{
					output << "--" << (*button).get_name() << endl;
					if ((*button).get_value() == "None")	
					{
						output << "--Button Binding has not been set\n" << endl;
					} else {
						output << "function d" << itd << "_b" << itb << "_event(value)" << endl;
						if ((*button).get_binding().find("Button") != string::npos)
						{
							output << "\tif value == 1 then" << endl;
							output << "\t\tsend_button_event" << "(0, " << (*button).get_value() << ", 1)" << endl;
							output << "\telse" << endl;
							output << "\t\tsend_button_event" << "(0, " << (*button).get_value() << ", 0)" << endl;
							output << "\tend" << endl;
						} else {
							output << "\tif value == 1 then" << endl;
							output << "\t\tsend_keyboard_event" << "(" << (*button).get_value() << ", 1)" << endl;
							output << "\telse" << endl;
							output << "\t\tsend_keyboard_event" << "(" << (*button).get_value() << ", 0)" << endl;
							output << "\tend" << endl;
						}
						output << "end" << endl;
					}
					itb++;
				}
			}	
		itd++;		
        }
    }
    output << "--End of Bindings" << endl;
	output.close();
    } else {
        cout << "Operation cancelled." << std::endl;
    }
}
