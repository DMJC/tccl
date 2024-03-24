#include "axis.h"
#include "axis_map.h"

Axis::Axis()
	{
	    /*Creating the Dataset for axis_dropdown*/
	    axis_refTreeModel = Gtk::ListStore::create(axis_columns);
	    axis_dropdown.set_model(axis_refTreeModel);
	    auto iter = axis_refTreeModel->append();
	    auto row = *iter;
	    row[axis_columns.axis_col_id] = 0;
	    row[axis_columns.axis_col_name] = axis_maps[0][1];
	    row[axis_columns.axis_col_value] = axis_maps[0][0];
  	    axis_dropdown.set_active(iter);
            int axis_list_size = *(&axis_maps + 1) - axis_maps;
	    for(int i = 1; i < axis_list_size; i++){
		  row = *(axis_refTreeModel->append());
		  row[axis_columns.axis_col_id] = i;
		  row[axis_columns.axis_col_name] = axis_maps[i][1];
		  row[axis_columns.axis_col_value] = axis_maps[i][0];
	    }
 	    axis_dropdown.pack_start(axis_columns.axis_col_name);
	    /*Creating the Widget*/
	    add(axis_box);
		this->inverted = 0;
	    this->axis_label.set_label("X-Axis");
	    this->axis_label.set_width_chars(31);
	    this->axis_button.set_hexpand(TRUE);
	    this->axis_button.set_image_from_icon_name("gtk-go-forward");
	    this->axis_button.set_hexpand(FALSE);
	    this->axis_invert.set_label("Invert: ");
	    this->axis_box.pack_start(axis_label);
	    this->axis_label.set_halign(Gtk::ALIGN_END);
	    axis_label.set_halign(Gtk::ALIGN_END);
	    this->axis_box.pack_start(axis_dropdown);
	    this->axis_box.pack_start(axis_invert);
	    axis_dropdown.signal_changed().connect( sigc::mem_fun(*this, &Axis::on_combo_changed) );
//	    axis_labeleb.signal_button_press_event().connect( sigc::bind(sigc::mem_fun(*this, &Axis::on_axis_label_clicked));
	    axis_button.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Axis::on_axis_button_clicked), "button 1"));
	    axis_invert.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Axis::on_axis_invert_clicked), "button 1"));
	    this->axis_box.pack_start(axis_button);
	    this->axis_setting_label.set_width_chars(20);
	    this->axis_box.pack_start(axis_setting_label);
	    this->axis_box.show_all();
		this->value = "None";
}

void Axis::on_axis_label_clicked(GdkEventButton* event)
{

}

void Axis::on_axis_invert_clicked(const Glib::ustring& data)
{
   cout << "Set Axis to Invert" << endl;
   if (this->inverted == 0)
   {
       this->set_inverted(1);
   } 
   else 
   {
       this->set_inverted(0);
   }
}

void Axis::set_value(string value)
{
	this->value = value;
}

string Axis::get_value(void)
{
	return this->value;
}

void Axis::on_axis_button_clicked(const Glib::ustring& data)
{
	const auto iter = axis_dropdown.get_active();
    const auto row = *iter;
	this->axis_setting_label.set_text(row[axis_columns.axis_col_name]);
	Glib::ustring temp = row[axis_columns.axis_col_value];
	this->set_value(temp.c_str());
}

string Axis::get_name(void)
{
	return this->axis_label.get_text();
}

void Axis::on_combo_changed()
{
    const auto iter = axis_dropdown.get_active();
    if(iter)
    {
        const auto row = *iter;
        if(row)
        {
            //Get the data for the selected row, using our knowledge of the tree
            //model:
            int id = row[axis_columns.axis_col_id];
            Glib::ustring name = row[axis_columns.axis_col_name];
      		Glib::ustring value = row[axis_columns.axis_col_value];
        }
    }
  else
  cout << "invalid iter" << endl;
}

int Axis::get_inverted(void)
{
 	return this->inverted;
}

void Axis::set_inverted(int invert)
{
	this->inverted = invert;
}

Axis::Axis(int device, string label, string description)
: Axis()
{
	this->inverted = 0;
	this->device = device;
	this->axis_label.set_label(label);
	this->axis_label.set_halign(Gtk::ALIGN_END);
	axis_label.set_halign(Gtk::ALIGN_END);
	this->axis_label.set_justify(Gtk::JUSTIFY_RIGHT);
	this->axis_dropdown.set_active_id(description);
	this->value = "None";
}

string Axis::get_mapping()
{
	return this->axis_label.get_text();
}
