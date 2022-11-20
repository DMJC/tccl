#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm/checkbutton.h>
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <gtkmm/window.h>
#include "device_box.h"

using namespace std;

class Main_Window : public Gtk::Window
{

public:
  Main_Window();
  virtual ~Main_Window();

protected:
  //Member widgets:
  Gtk::Box w_box;
  Device_Box dev_box;
};

#endif // MAIN_WINDOW_H
