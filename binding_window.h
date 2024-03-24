#ifndef BINDING_WINDOW_H
#define BINDING_WINDOW_H

#include <gtkmm/paned.h>
#include <gtkmm/button.h>
#include <gtkmm/entry.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <gtkmm/window.h>
#include <iostream>
#include <libudev.h>
#include <vector>
#include "device_box.h"
#include "axis_box.h"
#include "joy_button_box.h"

using namespace std;

class Binding_Window : public Gtk::Window
{

public:
  Binding_Window();
  virtual ~Binding_Window();
  //Member widgets:
  Gtk::Box* ab_box_ref;
  Gtk::Box binding_box;
  Gtk::ScrolledWindow binding_scrolled_box;
  Gtk::Entry profile_name_entry;
  Gtk::Button save_button;
  Gtk::Button close_button;
  vector<string> active_devids;
  vector<string> active_models;
  vector<Axis_Box> axis_bindings;
  vector<Joy_Button_Box> button_bindings;
  int buttons;
  int axes;
protected:
  void set_active_devices(vector<string>);
  vector<string>get_active_devices(void);
  void set_active_models(vector<string>);
  vector<string>get_active_models(void);
  void on_save_button_clicked(const Glib::ustring& data);
  void on_close_button_clicked(const Glib::ustring& data);
};

#endif // BINDING_WINDOW_H
