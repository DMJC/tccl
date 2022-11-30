#ifndef AXIS_WINDOW_H
#define AXIS_WINDOW_H

#include <gtkmm/button.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <gtkmm/window.h>
#include "device_box.h"
#include "axis_box.h"

using namespace std;

class Axis_Window : public Gtk::Window
{

public:
  Axis_Window();
  virtual ~Axis_Window();
  //Member widgets:
  Gtk::Box axes_w_box;
  Gtk::ScrolledWindow axes_s_box;
  Gtk::Button next_button;
  Device_Box dev_box;
  std::vector<Axis_Box*> all_device_axis_boxes;
protected:
  void on_next_button_clicked(const Glib::ustring& data);
};

#endif // AXIS_WINDOW_H
