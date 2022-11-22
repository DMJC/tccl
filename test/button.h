#ifndef BUTTON_H
#define BUTTON_H
#include <gtkmm/comboboxtext.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>
using namespace std;

class Button : public Gtk::Box
{
public:

	Button()
	{
	    set_border_width(10);
	    add(button_box);
	    button_label.set_label("Joy-0");
	    button_button.set_image_from_icon_name("gtk-go-forward");
	    button_dropdown.set_active_text("yo");
	    button_box.pack_start(button_label);
	    button_box.pack_start(button_dropdown);
	    button_box.pack_start(button_button);
	    show_all();
	}

	Button(std::string label, std::string description) : Button()
	{
		this->button_label.set_label(label);
		this->button_dropdown.set_active_text(description);
	}

protected:
	/*member widgets*/
	Gtk::Box button_box;
	Gtk::Button button_button;
	Gtk::Label button_label;
	Gtk::ComboBoxText button_dropdown;
};
#endif /*BUTTON_H*/
