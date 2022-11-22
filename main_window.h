#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm/checkbutton.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/window.h>
#include "device_box.h"
#include <sigc++/connection.h>

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
  Gtk::Box w_box;
  Gtk::ScrolledWindow s_window;
  Gtk::Box d_box;
  Gtk::Button load_profile_button;
  Gtk::Button create_profile_button;
};

#endif // MAIN_WINDOW_H
