#include "main_window.h"
//#include "debug.h"

Main_Window::Main_Window()
{
	this->profile_tracker = 0;
	set_title("TCCL");
	set_border_width(10);
	add(w_box);
	this->w_box.add(load_profile_button);
	w_box.set_property("orientation", Gtk::ORIENTATION_VERTICAL);
	this->load_profile_button.set_label("Load Profile");
	load_profile_button.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Main_Window::on_load_profile_button_clicked), "button 1"));
	create_profile_button.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Main_Window::on_create_profile_button_clicked), "button 2"));
	this->w_box.set_hexpand(TRUE);
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
/*	if (!devices) {
		fprintf(stderr, "Failed to get device list.\n");
		fprintf(stderr, "Re-run after connecting at least one supported device.\n");
		exit(1);
	}*/
	int i = -1;
	udev_list_entry_foreach(dev_list_entry, devices) 
	{
		i++;
	}

	std::string name = "button";
	this->all_devices;
	udev_list_entry_foreach(dev_list_entry, devices) 
	{
		const char *devmodel, *devpath, *name, *path;
		path = udev_list_entry_get_name(dev_list_entry);
		dev = udev_device_new_from_syspath(udev, path);
		/* device attributes */
		devmodel = udev_device_get_sysattr_value(dev, "id/product");
		string devmodel_img = (string)devmodel + ".png";
		devmodel_img = "images/" + devmodel_img;
		devpath = udev_device_get_devpath(dev);
		name =  udev_device_get_sysattr_value(dev, "name");
/*		cout << "Name: " << name << endl; cout << "Devmodel: " << devmodel << endl; cout << "Devmodel_img: " << devmodel_img << endl;*/
		Device_Box *dev_box = new Device_Box(name, devmodel, devmodel_img, i);
		this->all_devices.push_back(dev_box);
		i--;
		d_box.add(*dev_box);
	}
	/* free enumerate */
	udev_enumerate_unref(enumerate);
	/* free udev */
	udev_unref(udev);
	/*test data disable in prod scenarios.*/
	Device_Box *dev_box_0 = new Device_Box("Thrustmaster HOTAS Warthog","0402","images/0402.png",0);
	this->all_devices.push_back(dev_box_0);
        d_box.add(*dev_box_0);

	Device_Box *dev_box_1 = new Device_Box("Thrustmaster HOTAS Warthog Throttle","0404","images/0404.png",1);
	this->all_devices.push_back(dev_box_1);
        d_box.add(*dev_box_1);

	Device_Box *dev_box_2 = new Device_Box("Thrustmaster Pendular Rudder Pedals","b68f","images/b68f.png",2);
	this->all_devices.push_back(dev_box_2);
        d_box.add(*dev_box_2);
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
	if (profile_tracker == 1)
	{
		cout << "Clearing bindings window" << endl;
   		Gtk::Box& bindings_box = this->ab_box;
    		// Clear all children from the container
    		auto children = bindings_box.get_children();
    		for (auto& child : children)
		{
        		bindings_box.remove(*child);
		}
		this->bindings_window.binding_scrolled_box.remove();
   	}
	int size = 0;
	size = this->all_devices.size();
	this->ab_box.set_property("orientation", Gtk::ORIENTATION_VERTICAL);
	this->profile_label.set_text("Profile Name: ");
	this->profile_name_box.set_property("orientation", Gtk::ORIENTATION_HORIZONTAL);
	this->profile_name_box.add(profile_label);
	this->bindings_window.profile_name_entry.set_hexpand(TRUE);
	this->profile_name_box.add(this->bindings_window.profile_name_entry);
	this->ab_box.add(profile_name_box);
	int valid_devs = 0;
	int i = 0;
    int d = 0;
    int total_buttons = 0;
    int total_axes = 0;
	this->bindings_window.axes = 0;
	this->bindings_window.buttons = 0;
        for(i = 0; i < size; i++){
		int active = this->all_devices[i]->get_active();
		if (active == 1){
			string image= this->all_devices[i]->get_image();
			string devid = this->all_devices[i]->get_devid();
			string model = this->all_devices[i]->get_model();
			this->bindings_window.active_devids.push_back(devid);
			this->bindings_window.active_models.push_back(model);
			/*Test for Cougar MFDs (Devices with no Axes)*/
			if (this->all_devices[i]->get_devid() != "b351" || "b352")
			{
    			Axis_Box *dev_axe_box = new Axis_Box(this->all_devices[i]->get_axes(), this->all_devices[i]->get_image(), this->all_devices[i]->get_devid(), this->all_devices[i]->get_model(), i);
				this->ab_box.add(*dev_axe_box);
				Gtk::Separator *separator_axis = Gtk::manage(new Gtk::Separator(Gtk::ORIENTATION_HORIZONTAL));
				this->ab_box.add(*separator_axis);
				size_t axis_count = this->all_devices[i]->get_axes().size();
				total_axes = total_axes + axis_count;
				this->bindings_window.axes = total_axes;
			}
			/*Test for Rudder Pedals (Devices with no Buttons)*/
			if (this->all_devices[i]->get_devid() != "b68f" /*|| "RUDDERS GO HERE"*/)
			{
    			Joy_Button_Box *dev_but_box = new Joy_Button_Box(this->all_devices[i]->get_buttons(), this->all_devices[i]->get_image(), this->all_devices[i]->get_devid(), this->all_devices[i]->get_model(), i);
				this->ab_box.add(*dev_but_box);
				Gtk::Separator *separator_button = Gtk::manage(new Gtk::Separator(Gtk::ORIENTATION_HORIZONTAL));
				this->ab_box.add(*separator_button);
				size_t button_count = this->all_devices[i]->get_buttons().size();
				total_buttons = total_buttons + button_count;
				this->bindings_window.buttons = total_buttons;
			}
			valid_devs++;
		}
	}
	if (valid_devs == 0 && i == size) {
		cout << "There are no devices selected for this profile" << endl;
	}else{
		this->bindings_window.binding_scrolled_box.add(ab_box);
		Gtk::Button save_button;
		this->ab_box.add(this->bindings_window.save_button);
		Gtk::Button close_button;
		this->ab_box.add(this->bindings_window.close_button);
		this->bindings_window.ab_box_ref = &this->ab_box;
		this->bindings_window.binding_box.show_all();
		this->bindings_window.show();
	}
	this->profile_tracker = 1;
}
