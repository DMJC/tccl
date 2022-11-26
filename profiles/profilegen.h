#ifndef PROFILEGEN_H
#define PROFILEGEN_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std

class Profile

{
public:
    Profile::Profile();
    Profile::Profile(string, string) : Profile();
    Profile::create_axis_binding(string description, int device, int axis, int bound_axis, int invert);
    Profile::create_button_binding(string description, int device, int button, int bound_button, int use_alternate, int alternate_button);
    Profile::create_button_keyboard_binding(string description, int device, int button, string bound_key, int use_alternate, string bound_key2);
private:
    string profile_name;
    string profile_desc;
    ofstream profile;
};

#endif //PROFILEGEN_H



