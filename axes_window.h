#ifndef AXES_WINDOW_H
#define AXES_WINDOW_H

#include <gtkmm/checkbutton.h>
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <gtkmm/window.h>
#include "device_box.h"

using namespace std;

class Axes_Window : public Gtk::Window
{

public:
  Axes_Window();
  virtual ~Axes_Window();

protected:
  //Member widgets:
  Gtk::Box w_box;
  Device_Box dev_box;
};

#endif // AXES_WINDOW_H
