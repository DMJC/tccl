#ifndef AXIS_H
#define AXIS_H
#include <gtkmm/comboboxtext.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/eventbox.h>
#include <gtkmm/liststore.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <iostream>

using namespace std;

class Axis : public Gtk::Box
{
public:
	Axis();
	void on_axis_label_clicked(GdkEventButton*);
	void on_axis_button_clicked(const Glib::ustring&);
	void on_axis_invert_clicked(const Glib::ustring&);
	Axis(int, string, string);
	string get_mapping();
	int device;
	int axis;
	string get_name(void);
	int get_inverted(void);
	void set_inverted(int);
	void set_value(string);
	string get_value(void);
protected:
	void on_combo_changed();

	  //Tree model columns:
	  class ModelColumns : public Gtk::TreeModel::ColumnRecord
	  {
	  public:

	    ModelColumns()
	    { add(axis_col_id); add(axis_col_name); add(axis_col_value);}

	    Gtk::TreeModelColumn<int> axis_col_id;
	    Gtk::TreeModelColumn<Glib::ustring> axis_col_name;
	    Gtk::TreeModelColumn<Glib::ustring> axis_col_value;
	  };
	int inverted;
	string value;
	ModelColumns axis_columns;
	Glib::RefPtr<Gtk::ListStore> axis_refTreeModel;
	Gtk::Box axis_box;
	Gtk::CheckButton axis_invert;
	Gtk::Button axis_button;
	Gtk::EventBox axis_labeleb;
	Gtk::Label axis_label;
	Gtk::ComboBox axis_dropdown;
	Gtk::Label axis_setting_label;
};
#endif /*AXIS_H*/
