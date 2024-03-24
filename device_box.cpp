#include "device_box.h"
#include <iostream>

Device_Box::Device_Box()
{
    set_border_width(10);
    add(m_box);
    this->device_active = 0;
    m_box.set_property("orientation", Gtk::ORIENTATION_VERTICAL);
    m_label.set_label("Thrustmaster Warthog Throttle");
    m_button.set_label("Add device to Profile");
    m_button.signal_toggled().connect(sigc::mem_fun(*this,&Device_Box::on_button_toggled) );
    m_box.pack_start(m_label);
    m_box.pack_start(m_image);
    m_box.pack_start(m_button);
    show_all();
}

void Device_Box::on_button_toggled()
{
  std::cout << "Device ID: " << this->m_model << " Device: " << this->device_number << " Toggled: "<< (m_button.get_active() ? "true" : "false") << std::endl;
  bool state = m_button.get_active();
  if (state == true){
    this->device_active=1;
  }else{
    this->device_active=0;
  }
}

string Device_Box::get_devid(void)
{
 	return this->m_model;
}

string Device_Box::get_image(void)
{
	return this->img_buffer;
}

string Device_Box::get_model(void)
{
	return this->m_label.get_text();
}

int Device_Box::get_active(void)
{
	return this->device_active;
}

vector<vector<string>> Device_Box::get_axes(void)
{
	return this->axes;
}
vector<vector<string>> Device_Box::get_buttons(void)
{
	return this->buttons;
}

void Device_Box::Initialize()
{
  this->s_mapStringValues["0402"] = evWarthog_Stick;
  this->s_mapStringValues["0404"] = evWarthog_Throttle;
  this->s_mapStringValues["b68f"] = evPendular_Rudder;
  this->s_mapStringValues["0400"] = evCougar_Stick;
  this->s_mapStringValues["b351"] = evCougarMFD1;
  this->s_mapStringValues["b352"] = evCougarMFD2;
  this->s_mapStringValues["b10a"] = evTFlight_Stick;
  this->s_mapStringValues["b678"] = evTFlight_Rudder;
  this->s_mapStringValues["b687"] = evTWCS_Throttle;
  this->s_mapStringValues[""] = evEnd;
}

Device_Box::Device_Box(std::string label, std::string model, std::string model_img, int dev_number) : Device_Box()
{
    cout << "Label: " << label << " model: " << model << endl;
    this->Initialize();
    this->m_label.set_label(label);
    this->m_image.set(model_img);
    this->m_model = model;
    this->img_buffer = model_img;
    this->device_number = dev_number;

    switch(s_mapStringValues[model])
    {
      case evWarthog_Stick:{
        cout << "ThrustMaster HOTAS Warthog Stick." << endl;
    	this->axes = warthog_stick_axes();
	this->buttons = warthog_stick_buttons();
        break;}
      case evWarthog_Throttle:
      {
        cout << "ThrustMaster HOTAS Warthog Throttle." << endl;
    	this->axes = warthog_throttle_axes();
	this->buttons = warthog_throttle_buttons();
        break;
      }
      case evPendular_Rudder:
      {
        cout << "ThrustMaster Pendular Rudder Pedals." << endl;
	this->axes = pendular_rudder_axes();
        break;
      }
      case evCougar_Stick:{
	cout << "ThrustMaster HOTAS Cougar." << endl;
    	this->axes = cougar_stick_axes();
	this->buttons = cougar_stick_buttons();
        break;
      }
      case evCougarMFD1:
      {
        cout << "ThrustMaster Cougar MFD1" << endl;
	this->buttons = cougar_mfd_buttons();
        break;}
      case evCougarMFD2:{
        cout << "ThrustMaster Cougar MFD2" << endl;
	this->buttons = cougar_mfd1_buttons();
        break;}
      case evTFlight_Stick:{
        cout << "ThrustMaster T.16000M Joystick" << endl;
//	this->axes = 
//	this->buttons = 
        break;}
      case evTFlight_Rudder:{
        cout << "ThrustMaster T.Flight Rudder Pedals" << endl;
	this->axes = tflight_rudder_axes();
        break;}
      case evTWCS_Throttle:{
        cout << "ThrustMaster TWCS Throttle" << endl;
//	this->axes = 
//	this->buttons = 
        break;}
      case evEnd:
        cout << "FAILED, BIG PROBLEM MATE." << endl;
      default:
        cout << "'" << dev_number << "' is an invalid string. s_mapStringValues now contains "
             << s_mapStringValues.size()
             << " entries." << endl;
        break;
    }
    show_all();
}
