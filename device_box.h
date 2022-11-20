#ifndef DEVICE_BOX_H
#define DEVICE_BOX_H

#include <gtkmm/checkbutton.h>
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>

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
    m_box.pack_start(m_label);
    m_box.pack_start(m_image);
    m_box.pack_start(m_button);
    show_all();
  }

  Device_Box(std::string label, std::string model) : Device_Box()
  {
   this->m_label.set_label(label);
   this->m_image.set(model);
  }

  virtual ~Device_Box();
protected:
  //Member widgets:
  Gtk::Box m_box;
  Gtk::Image m_image;
  Gtk::CheckButton m_button;
};

#endif // DEVICE_BOX_H
