#ifndef AXES_BOX_H
#define AXES_BOX_H

#include <gtkmm/checkbutton.h>
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>

class Axes_Box : public Gtk::Box
{
  Gtk::Label a_label;

public:
  Axes_Box()
  {
    set_border_width(10);
    add(a_box);
    a_box.set_property("orientation", Gtk::ORIENTATION_VERTICAL);
    a_label.set_label("Thrustmaster Warthog");
    a_button.set_label("Add Axes to Profile");
    a_box.pack_start(a_label);
    a_box.pack_start(a_image);
    a_box.pack_start(a_button);
    show_all();
  }

  Axes_Box(std::string label, std::string model) : Axes_Box()
  {
   this->a_label.set_label(label);
   this->a_image.set(model);
  }

  virtual ~Axes_Box();
protected:
  //Member widgets:
  Gtk::Box a_box;
  Gtk::Image a_image;
  Gtk::CheckButton a_button;
};

#endif // AXES_BOX_H
