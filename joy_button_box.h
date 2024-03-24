#ifndef JOY_BUTTON_BOX_H
#define JOY_BUTTON_BOX_H
#include <gtkmm/box.h>
#include <gtkmm/fixed.h>
#include <gtkmm/label.h>
#include <gtkmm/image.h>
#include <gtkmm/scrolledwindow.h>
#include <vector>
#include "joy_button.h"

using namespace std;

class Joy_Button_Box : public Gtk::Box
{
public:
  Joy_Button_Box();
  Joy_Button_Box(vector<vector<string> >, string, string, string, int);
  void get_bindings();
  Gtk::Box* get_button_boxes();
  virtual ~Joy_Button_Box();
protected:
  //Member widgets:
  Gtk::Box joy_button_box;
  Gtk::Label device_label;
  Gtk::Box v_box;
  Gtk::Box h_box;
  Gtk::Fixed i_fixed;
  Gtk::Box w_box;
  Gtk::Image dev_image;
  Joy_Button joy_button;
};

#endif // JOY_BUTTON_BOX_H
