#include "axis_window.h"
#include <iostream>
#include <libudev.h>

Axis_Window::Axis_Window()
{
  set_title("TCCL - AXIS Mapping");
  set_border_width(10);
  add(axes_s_box);
  this->axes_s_box.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
//  this->axes_s_box.set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);
//  this->axes_s_box.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_NEVER);
  this->axes_s_box.set_propagate_natural_width(TRUE);
  this->axes_s_box.set_propagate_natural_height(TRUE);
  this->axes_s_box.add(axes_w_box);
  this->axes_s_box.show_all();
}

Axis_Window::~Axis_Window()
{
}
