#include <iostream>
#include <fstream>

using namespace std;

void create_axis_binding(ofstream& profile, string description, int device, int axis, int bound_axis, int invert) {
	profile << "-- " << description << endl;
	profile << "function d" << device << "_a"<< axis;
	if (invert == 1){
		profile << "_event(-value)" << endl;
	}else{
		profile  << "_event(value)" << endl;
	}
	profile << "      send_axis_event(0, " << bound_axis << ", value)" << endl;
	profile << "end\n" << endl;
}

void create_button_binding(ofstream& profile, string description, int device, int button, int bound_button, int use_alternate, int alternate_button) {
	profile << "-- " << description << endl;
	profile << "function d" << device << "_b"<< button << "_event(value)" << endl;
	profile << "      send_axis_event(0, " << bound_button << ", value)" << endl;
	if (use_alternate == 1 ){
		profile <<"\tend" << endl;
	}
	profile << "end\n" << endl;

	if (use_alternate == 1 ){
		profile << "   if value == 1 then" << endl;
	}

void create_button_keyboard_binding(ofstream& profile, string description, int device, int button, int bound_button, int use_alternate, int alternate_button) {
	profile << "-- " << description << endl;
	profile << "function d" << device << "_b"<< button << "_event(value)" << endl;
	profile << "      send_axis_event(0, " << bound_button << ", value)" << endl;
	if (use_alternate == 1 ){
		profile <<"\tend" << endl;
	}
	profile << "end\n" << endl;

	if (use_alternate == 1 ){
		profile << "   if value == 1 then" << endl;
	}





function d1_b0_event(value)
   if value == 1 then
      send_keyboard_event(KEY_A, 1)
   else
      send_keyboard_event(KEY_A, 0)
   end
end


}

int main(){
	string profile_name = "profile name";
	string profile_desc = "profile description goes in here";
	ofstream profile;
	profile.open("profile.lua");
	profile << "-- " << profile_name << endl;
	profile << "-- " << profile_desc << endl;
	profile << "devices =\n   {\n" << endl;

	string device_array[]={"0x0402","0x0404","0x0402"};
/*
	for (){
		profile << "d" << i << " = " -- << /*Description var goes here*//* "\n\t {\n\t\t vendorid = 0x044f," << endl;
		profile << "\t\tproductid = " << device_array[i] << ",\n\t },\n" << endl;
	}
*/
	profile << "   }" << endl;
	profile << "-- Virtual devices \n" << "v_devices =\n" << "   {\n" << "      v0 =\n" << "         {" << endl;
	profile << "            buttons = 51,\n" << "            axes = 14\n" << "         }\n" << "   }\n" << endl;

	create_axis_binding(profile, "X-axis", 0, 1, 1, 1);
	create_axis_binding(profile, "Y-axis", 1, 1, 2, 0);

	profile.close();
	return 0;
}
