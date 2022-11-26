#include "profilegen.h"

Profile::create_axis_binding(string description, int device, int axis, int bound_axis, int invert) {
	this->profile << "-- " << description << endl;
	this->profile << "function d" << device << "_a"<< axis;
	if (invert == 1){
		this->profile << "_event(-value)" << endl;
	}else{
		this->profile  << "_event(value)" << endl;
	}
	this->profile << "      send_axis_event(0, " << bound_axis << ", value)" << endl;
	this->profile << "end\n" << endl;
}

Profile::create_button_binding(string description, int device, int button, int bound_button, int use_alternate, int alternate_button) {
	this->profile << "-- " << description << endl;
	this->profile << "function d" << device << "_b"<< button << "_event(value)" << endl;
	this->profile << "   if value == 1 then" << endl;
	this->profile << "      send_button_event(0, " << bound_button << ", " << 1 << ")" << endl;
	this->profile << "   else" << endl;
	this->profile << "      send_button_event(0, " << bound_button << ", " << 0 << ")" << endl;
	this->profile << "   end" << endl;
	this->profile << "end\n" << endl;
}

Profile::create_button_keyboard_binding(string description, int device, int button, string bound_key, int use_alternate, string bound_key2) {
	this->profile << "function d" << device << "_b"<< button << "_event(value)" << endl;
	this->profile << "   if value == 1 then" << endl;
	this->profile << "      send_keyboard_event(" << bound_key << ", 1)" << endl;
	this->profile << "   else" << endl;
	this->profile << "      send_keyboard_event(" << bound_key2 << ", 0)" << endl;
	this->profile << "   end" << endl;
	this->profile << "end\n" << endl;
}

Profile::Profile(string name, string description, vector<string> &devices)
: Profile()
{
	this->profile_name = name;
	this->profile_desc = description;
	this->profile.open("profile.lua");
	this->profile << "-- " << profile_name << endl;
	this->profile << "-- " << profile_desc << endl;
	this->profile << "devices =\n   {\n" << endl;
/*	for(int i=0; i < devices.size(); i++){
		profile << "d" << i << " = " -- << /*Description var goes here*/ /*"\n\t {\n\t\t vendorid = 0x044f," << endl;
		profile << "\t\tproductid = " << device_array[i] << ",\n\t },\n" << endl;
	   devices[i].doSomething();
	}
	this->profile << "   }" << endl;
	this->profile << "-- Virtual devices \n" << "v_devices =\n" << "   {\n" << "      v0 =\n" << "         {" << endl;
	this->profile << "            buttons = 51,\n" << "            axes = 14\n" << "         }\n" << "   }\n" << endl;
*/

}

/*
	create_button_keyboard_binding(profile, "Trigger", 0, 1, 1, 0, 0);
	create_button_keyboard_binding(profile, "Weapon Release", 0, 1, 1, 0, 0);

	create_button_binding(profile, "Trigger", 0, 1, 1, 0, 0);
	create_button_binding(profile, "Weapon Release", 0, 3, 3, 1, 1);

	create_axis_binding(profile, "X-axis", 0, 0, 1, 1);
	create_axis_binding(profile, "Y-axis", 0, 1, 2, 0);

	profile.close();
	return 0;
}
*/
