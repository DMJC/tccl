#ifndef AXIS_H
#define AXIS_H
#include <gtkmm/comboboxtext.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>
using namespace std;

class Axis : public Gtk::Box
{
public:

	Axis()
	{
	    set_border_width(10);
	    add(axis_box);
	    axis_label.set_label("X-Axis");
	    axis_button.set_image_from_icon_name("gtk-go-forward");
	    axis_dropdown.set_active_text("yo");
	    axis_box.pack_start(axis_label);
	    axis_box.pack_start(axis_dropdown);
	    axis_box.pack_start(axis_button);
	    show_all();
	}

	Axis(std::string label, std::string description) : Axis()
	{
		this->axis_label.set_label(label);
		this->axis_dropdown.set_active_text(description);
	}
//virtual ~Axis();

protected:
	/*member widgets*/
	Gtk::Box axis_box;
	Gtk::Button axis_button;
	Gtk::Label axis_label;
	Gtk::ComboBoxText axis_dropdown;
};
#endif /*AXIS_H*/
