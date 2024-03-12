#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm/paned.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/window.h>
#include "device_box.h"
#include "axis_window.h"
#include "axis_box.h"
//#include "joy_button_window.h"
#include "joy_button_box.h"
#include <vector>
#include <iostream>
#include <libudev.h>

using namespace std;

class Main_Window : public Gtk::Window
{

public:
  Main_Window();
  virtual ~Main_Window();

protected:
  void on_load_profile_button_clicked(const Glib::ustring& data);
  void on_create_profile_button_clicked(const Glib::ustring& data);
  //Member widgets:
  Axis_Window axes_window;
//  Joy_Button_Window joy_button_window;
  Gtk::Box w_box;
  Gtk::ScrolledWindow s_window;
  Gtk::Box d_box;
  Gtk::Box ab_box;
  Gtk::Button load_profile_button;
  Gtk::Button create_profile_button;
  std::vector<Device_Box*> all_devices;
};

#endif // MAIN_WINDOW_H
