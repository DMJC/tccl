#ifndef AXIS_BOX_H
#define AXIS_BOX_H
#include <gtkmm/box.h>
#include <gtkmm/fixed.h>
#include <gtkmm/label.h>
#include <gtkmm/image.h>
#include <gtkmm/scrolledwindow.h>
#include <vector>
#include "axis.h"

using namespace std;

class Axis_Box : public Gtk::Box
{
public:
  Axis_Box();
  Axis_Box(vector<vector<string> >, string, string, string, int);
  Gtk::Box* get_axis_boxes();
  virtual ~Axis_Box();
protected:
  //Member widgets:
  Gtk::Box axis_box;
  Gtk::Label device_label;
  Gtk::Box v_box;
  Gtk::Fixed i_fixed;
  Gtk::Box h_box;
  Gtk::Box w_box;
  Gtk::Image dev_image;
  Axis axis;
};

#endif // AXIS_BOX_H
