#ifndef AXIS_H
#define AXIS_H
#include <gtkmm/comboboxtext.h>
#include <gtkmm/liststore.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>
#include <iostream>

using namespace std;

class Axis : public Gtk::Box
{
public:
	Axis();
	Axis(std::string, std::string);
protected:
	void on_combo_changed();

	  //Tree model columns:
	  class ModelColumns : public Gtk::TreeModel::ColumnRecord
	  {
	  public:

	    ModelColumns()
	    { add(axis_col_id); add(axis_col_name);}

	    Gtk::TreeModelColumn<int> axis_col_id;
	    Gtk::TreeModelColumn<Glib::ustring> axis_col_name;
	  };

	ModelColumns axis_columns;
	Glib::RefPtr<Gtk::ListStore> axis_refTreeModel;
	Gtk::Box axis_box;
	Gtk::Button axis_button;
	Gtk::Label axis_label;
	Gtk::ComboBox axis_dropdown;
};
#endif /*AXIS_H*/
