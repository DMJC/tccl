#include "joy_button.h"
#include "joy_button_map.h"

Joy_Button::Joy_Button()
	{
	    /*Creating the Dataset for joy_button_dropdown*/
	    joy_button_refTreeModel = Gtk::ListStore::create(joy_button_columns);
	    joy_button_dropdown.set_model(joy_button_refTreeModel);
	    auto iter = joy_button_refTreeModel->append();
	    auto row = *iter;

	    row[joy_button_columns.joy_button_col_id] = 0;
	    row[joy_button_columns.joy_button_col_name] = joy_button_maps[0][1];
	    row[joy_button_columns.joy_button_col_value] = joy_button_maps[0][2];
  	    joy_button_dropdown.set_active(iter);
            int joy_button_list_size = *(&joy_button_maps + 1) - joy_button_maps;
	    for(int i = 1; i < joy_button_list_size; i++){
		  row = *(joy_button_refTreeModel->append());
		  row[joy_button_columns.joy_button_col_id] = i;
		  row[joy_button_columns.joy_button_col_name] = joy_button_maps[i][1];
		  row[joy_button_columns.joy_button_col_value] = joy_button_maps[i][2];
	    }
 	    joy_button_dropdown.pack_start(joy_button_columns.joy_button_col_name);

	    /*Creating the Widget*/
	    add(joy_button_box);
//	    this->joy_button_box.set_homogeneous(TRUE);
	    this->joy_button_label.set_label("X-Joy_Button");
		this->joy_button_label.set_width_chars(31);
		this->joy_button_label.set_halign(Gtk::ALIGN_END);
	    this->joy_button_button.set_image_from_icon_name("gtk-go-forward");
		this->joy_button_button.set_hexpand(FALSE);
	    this->joy_button_box.pack_start(joy_button_label);
	    this->joy_button_box.pack_start(joy_button_dropdown);
	    joy_button_dropdown.signal_changed().connect( sigc::mem_fun(*this, &Joy_Button::on_combo_changed) );
	    joy_button_button.signal_clicked().connect( sigc::bind(sigc::mem_fun(*this, &Joy_Button::on_joy_button_button_clicked), "button 1"));
	    this->joy_button_box.pack_start(joy_button_button);
	    this->joy_button_setting_label.set_width_chars(20);
	    this->joy_button_setting_label.set_halign(Gtk::ALIGN_END);
	    this->joy_button_box.pack_start(joy_button_setting_label);
	    this->joy_button_box.show_all();	
		this->value = "None";
}

void Joy_Button::set_value(string value)
{
	this->value = value;
}

string Joy_Button::get_value(void)
{
	return this->value;
}

void Joy_Button::on_joy_button_button_clicked(const Glib::ustring& data)
{
	const auto iter = joy_button_dropdown.get_active();
    const auto row = *iter;
	this->joy_button_setting_label.set_text(row[joy_button_columns.joy_button_col_name]);
	Glib::ustring temp = row[joy_button_columns.joy_button_col_value];
	this->set_value(temp.c_str());
}

string Joy_Button::get_name(void)
{
	return this->joy_button_label.get_text();
}

void Joy_Button::on_combo_changed()
{
  const auto iter = joy_button_dropdown.get_active();
  if(iter)
  {
    const auto row = *iter;
    if(row)
    {
      //Get the data for the selected row, using our knowledge of the tree
      //model:
      int id = row[joy_button_columns.joy_button_col_id];
      Glib::ustring name = row[joy_button_columns.joy_button_col_name];
      Glib::ustring value = row[joy_button_columns.joy_button_col_value];
      cout << " ID=" << id << ", Joy_Button Binding=" << name << " , Value: " << value << endl;
    }
  }
  else
    cout << "invalid iter" << endl;
}

string Joy_Button::get_binding(void)
{
	return this->joy_button_setting_label.get_text();
}

Joy_Button::Joy_Button(int device, string label, string description)
: Joy_Button()
{
	this->device = device;
	this->joy_button_label.set_label(label);
	this->joy_button_dropdown.set_active_id(description);
	this->value = "None";
}

string Joy_Button::get_mapping()
{
	return this->joy_button_label.get_text();
}
