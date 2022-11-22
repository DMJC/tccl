#ifndef DEVICE_BOX_H
#define DEVICE_BOX_H

#include <gtkmm/checkbutton.h>
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <string>
#include <iterator>
#include <iostream>

using namespace std;

class Device_Box : public Gtk::Box
{
  Gtk::Label m_label;

public:
  Device_Box()
  {
    set_border_width(10);
    add(m_box);
    m_box.set_property("orientation", Gtk::ORIENTATION_VERTICAL);
    m_label.set_label("Thrustmaster Warthog Throttle");
    m_button.set_label("Add device to Profile");
    m_button.signal_toggled().connect(sigc::mem_fun(*this,&Device_Box::on_button_toggled) );
    m_box.pack_start(m_label);
    m_box.pack_start(m_image);
    m_box.pack_start(m_button);
    show_all();
  }

  Device_Box(std::string label, std::string model, int dev_number) : Device_Box()
  {
   this->m_label.set_label(label);
   this->m_image.set(model);
   this->buffer = model;
   this->device_number = dev_number;
  }

protected:
  void on_button_toggled();
  //Member widgets:
  Gtk::Box m_box;
  Gtk::Image m_image;
  Gtk::CheckButton m_button;
  std::string buffer;
  int device_number;
};

#endif // DEVICE_BOX_H
