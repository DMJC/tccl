#ifndef JOY_BUTTON_H
#define JOY_BUTTON_H
#include <gtkmm/comboboxtext.h>
#include <gtkmm/liststore.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <iostream>

using namespace std;

class Joy_Button : public Gtk::Box
{
public:
	Joy_Button();
	void on_joy_button_button_clicked(const Glib::ustring&);
	Joy_Button(int, string, string);
	string get_mapping();
	int device;
	int button;
	string get_name(void);
	string get_binding(void);
	void set_value(string);
	string get_value(void);
protected:
	void on_combo_changed();

	  //Tree model columns:
	  class ModelColumns : public Gtk::TreeModel::ColumnRecord
	  {
	  public:

	    ModelColumns()
	    { add(joy_button_col_id); add(joy_button_col_name); add(joy_button_col_value);}

	    Gtk::TreeModelColumn<int> joy_button_col_id;
	    Gtk::TreeModelColumn<Glib::ustring> joy_button_col_name;
	    Gtk::TreeModelColumn<Glib::ustring> joy_button_col_value;
	  };
	string value;
	ModelColumns joy_button_columns;
	Glib::RefPtr<Gtk::ListStore> joy_button_refTreeModel;
	Gtk::Box joy_button_box;
	Gtk::Button joy_button_button;
	Gtk::Label joy_button_label;
	Gtk::ComboBox joy_button_dropdown;
	Gtk::Label joy_button_setting_label;
};
#endif /*JOY_BUTTON_H*/
