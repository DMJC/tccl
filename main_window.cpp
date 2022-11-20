#include "main_window.h"
#include <iostream>
#include <libudev.h>

Main_Window::Main_Window()
{
  set_title("TCCL");
  set_border_width(10);
  add(w_box);
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
        }

        int i = 0;
        udev_list_entry_foreach(dev_list_entry, devices) {
                i++;
        }

        std::string name = "button";
        std::map<std::string, Device_Box*> all_buttons;

        udev_list_entry_foreach(dev_list_entry, devices) {
                const char *devmodel, *devpath, *name, *path;
                path = udev_list_entry_get_name(dev_list_entry);
                dev = udev_device_new_from_syspath(udev, path);
                /* device attributes */
                devmodel =  udev_device_get_sysattr_value(dev, "id/product");
		string devmodel_img = strcat((char*)devmodel, ".png");
		devmodel_img = "images/" + devmodel_img;
                cout << devmodel << " ";
                devpath = udev_device_get_devpath(dev);
                cout << "DEVPATH=" << devpath << " ";
                name =  udev_device_get_sysattr_value(dev, "name");
                cout << name << endl;

		Device_Box *dev_box = new Device_Box(name, devmodel_img);
		all_buttons[name] = dev_box;
		i--;
		w_box.add(*dev_box);
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
