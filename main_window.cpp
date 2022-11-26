#include "main_window.h"
#include <iostream>
#include <libudev.h>
//#include "debug.h"

Main_Window::Main_Window()
{
	set_title("TCCL");
	set_border_width(10);
	add(w_box);
	w_box.set_property("orientation", Gtk::ORIENTATION_VERTICAL);
	this->w_box.add(load_profile_button);
	this->load_profile_button.set_label("Load Profile");
 	load_profile_button.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Main_Window::on_load_profile_button_clicked), "button 1"));
 	create_profile_button.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Main_Window::on_create_profile_button_clicked), "button 2"));
	this->w_box.add(s_window);
	this->s_window.add(d_box);
	this->s_window.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_NEVER);
	this->s_window.set_propagate_natural_width(TRUE);
	this->s_window.set_propagate_natural_height(TRUE);
	this->w_box.add(create_profile_button);
	this->create_profile_button.set_label("Create Profile");

        struct udev *udev;
        struct udev_device *dev;
        struct udev_enumerate *enumerate;
        struct udev_list_entry *devices, *dev_list_entry;

        /* create udev object */
        udev = udev_new();
        if (!udev) {
                fprintf(stderr, "Cannot create udev context.\n");
        }

        /* create enumerate object */
        enumerate = udev_enumerate_new(udev);
        if (!enumerate) {
                fprintf(stderr, "Cannot create enumerate context.\n");
        }

        udev_enumerate_add_match_sysattr(enumerate, "id/vendor" , "044f");
        udev_enumerate_scan_devices(enumerate);

        /* fillup device list */
        devices = udev_enumerate_get_list_entry(enumerate);
        if (!devices) {
                fprintf(stderr, "Failed to get device list.\n");
                fprintf(stderr, "Re-run after connecting at least one supported device.\n");
		exit(1);
        }

        int i = -1;
        udev_list_entry_foreach(dev_list_entry, devices) {
                i++;
        }

        std::string name = "button";
	this->all_buttons;
        udev_list_entry_foreach(dev_list_entry, devices) {
                const char *devmodel, *devpath, *name, *path;
                path = udev_list_entry_get_name(dev_list_entry);
                dev = udev_device_new_from_syspath(udev, path);
                /* device attributes */
                devmodel = udev_device_get_sysattr_value(dev, "id/product");
		string devmodel_img = strcat((char*)devmodel, ".png");
		devmodel_img = "images/" + devmodel_img;
//                cout << devmodel << " ";
                devpath = udev_device_get_devpath(dev);
//                cout << "DEVPATH=" << devpath << " ";
                name =  udev_device_get_sysattr_value(dev, "name");
                cout << name << endl;
		Device_Box *dev_box = new Device_Box(name, devmodel_img, i);
		this->all_buttons.push_back(dev_box);
		i--;
		d_box.add(*dev_box);
        }
        /* free enumerate */
        udev_enumerate_unref(enumerate);
        /* free udev */
        udev_unref(udev);

  w_box.show_all();
}

Main_Window::~Main_Window()
{
}

void Main_Window::on_load_profile_button_clicked(const Glib::ustring& data)
{
	cout << "Load a Profile Code" << endl;
}

void Main_Window::on_create_profile_button_clicked(const Glib::ustring& data)
{
	int size = this->all_buttons.size();
	int valid_devs = 0;
	int i = 0;
        for(i = 0; i < size; i++){
		int active = this->all_buttons[i]->get_active();
		if (active == 1){
/*			cout << this->all_buttons[i]->get_devid() << " ";
			cout << this->all_buttons[i]->get_image() << endl;*/
//			this->all_buttons[i]->get_devid(), this->all_buttons[i]->get_image();
			valid_devs++;
		}
	}
	if (valid_devs == 0 && i == size) {
		cout << "There are no devices selected for this profile" << endl;
	}else{
		cout << "Draw Window" << endl;
	}
}
