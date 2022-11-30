#ifndef AXIS_WINDOW_H
#define AXIS_WINDOW_H

#include <gtkmm/checkbutton.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <gtkmm/window.h>
#include "device_box.h"

using namespace std;

class Axis_Window : public Gtk::Window
{

public:
  Axis_Window();
  virtual ~Axis_Window();
  //Member widgets:
  Gtk::Box axes_w_box;
  Gtk::ScrolledWindow axes_s_box;
  Device_Box dev_box;

protected:
};

#endif // AXIS_WINDOW_H
