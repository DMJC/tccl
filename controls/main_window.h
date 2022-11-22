#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/scrolledwindow.h>
//#include "axis.h"
#include "button.h"

using namespace std;

class Main_Window : public Gtk::Window
{

public:
  Main_Window();
  virtual ~Main_Window();

protected:
  //Member widgets:
  Gtk::ScrolledWindow w_scrolledwindow;
  Gtk::Box w_box;
  Button axis;
};

#endif // MAIN_WINDOW_H
