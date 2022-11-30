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
  this->next_button.set_label("Next");
  next_button.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Axis_Window::on_next_button_clicked), "button 1"));
  this->axes_s_box.show_all();
}

Axis_Window::~Axis_Window()
{
}

void Axis_Window::on_next_button_clicked(const Glib::ustring& data)
{
	cout << "Clicked, time for Button Mappings!" << endl;
}
