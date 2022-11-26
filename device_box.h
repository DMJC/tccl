#ifndef DEVICE_BOX_H
#define DEVICE_BOX_H

#include <gtkmm/checkbutton.h>
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <string>
#include <map>
#include <iterator>
#include <iostream>
#include "devices/pendular_rudder.h"
#include "devices/tflight_hotas.h"
#include "devices/tflight_rudder.h"
#include "devices/warthog_stick.h"
#include "devices/warthog_throttle.h"

using namespace std;

class Device_Box : public Gtk::Box
{
  Gtk::Label m_label;

public:
  Device_Box();
  Device_Box(string label, string model, int dev_number);
  void Initialize(void);
  string get_devid(void);
  string get_image(void);
  int get_active(void);
  vector<vector<string>> get_axes(void);
  vector<vector<string>> get_buttons(void);
  enum StringValue { evNotDefined,evWarthog_Stick,evWarthog_Throttle,evPendular_Rudder,evCougar_Stick,evCougarMFD1,evCougarMFD2,evStringValue7,evStringValue8,evStringValue9,evEnd };
  std::map<std::string, StringValue> s_mapStringValues;
protected:
  void on_button_toggled();
  //Member widgets:
  Gtk::Box m_box;
  Gtk::Image m_image;
  Gtk::CheckButton m_button;
  std::string buffer;
  int device_number;
  int device_active;
  vector<vector<string>> axes;
  vector<vector<string>> buttons;
};

#endif // DEVICE_BOX_H
