#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/scrolledwindow.h>
#include "axis.h"
//#include "button.h"

using namespace std;

class Main_Window : public Gtk::Window
{

public:
  Main_Window();
  Main_Window(vector<vector<string>>);
  virtual ~Main_Window();

protected:
  //Member widgets:
  Gtk::ScrolledWindow w_scrolledwindow;
  Gtk::Box h_box;
  Gtk::Box w_box;
  Gtk::Image dev_image;
  Axis axis;
};

#endif // MAIN_WINDOW_H
