#include "button.h"
#include "button_map.h"

Button::Button()
	{
	    /*Creating the Dataset for button_dropdown*/
	    button_refTreeModel = Gtk::ListStore::create(button_columns);
	    button_dropdown.set_model(button_refTreeModel);
	    auto iter = button_refTreeModel->append();
	    auto row = *iter;

	    row[button_columns.button_col_id] = 0;
	    row[button_columns.button_col_name] = button_maps[0][1];
  	    button_dropdown.set_active(iter);
            int button_list_size = *(&button_maps + 1) - button_maps;
	    for(int i = 1; i < button_list_size; i++){
		  row = *(button_refTreeModel->append());
		  row[button_columns.button_col_id] = i;
		  row[button_columns.button_col_name] = button_maps[i][1];
	    }
 	    button_dropdown.pack_start(button_columns.button_col_name);

	    /*Creating the Widget*/
	    add(button_box);
	    this->button_label.set_label("Button");
	    this->button_button.set_image_from_icon_name("gtk-go-forward");
	    this->button_box.pack_start(button_label);
	    this->button_box.pack_start(button_dropdown);
	    button_dropdown.signal_changed().connect( sigc::mem_fun(*this, &Button::on_combo_changed) );
	    this->button_box.pack_start(button_button);
	    this->button_box.show_all();
}

void Button::on_combo_changed()
{
  const auto iter = button_dropdown.get_active();
  if(iter)
  {
    const auto row = *iter;
    if(row)
    {
      //Get the data for the selected row, using our knowledge of the tree
      //model:
      int id = row[button_columns.button_col_id];
      Glib::ustring name = row[button_columns.button_col_name];

      cout << " ID=" << id << ", Button Binding=" << name << endl;
    }
  }
  else
    cout << "invalid iter" << endl;
}

Button::Button(std::string label, std::string description)
: Button()
{
	this->button_label.set_label(label);
	this->button_dropdown.set_active_id(description);
}
