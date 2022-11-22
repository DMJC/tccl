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
  	    axis_dropdown.set_active(iter);
            int axis_list_size = *(&axis_maps + 1) - axis_maps;
	    for(int i = 1; i < axis_list_size; i++){
		  row = *(axis_refTreeModel->append());
		  row[axis_columns.axis_col_id] = i;
		  row[axis_columns.axis_col_name] = axis_maps[i][1];
	    }
 	    axis_dropdown.pack_start(axis_columns.axis_col_name);

	    /*Creating the Widget*/
	    add(axis_box);
	    this->axis_label.set_label("X-Axis");
	    this->axis_button.set_image_from_icon_name("gtk-go-forward");
	    this->axis_box.pack_start(axis_label);
	    this->axis_box.pack_start(axis_dropdown);
	    axis_dropdown.signal_changed().connect( sigc::mem_fun(*this, &Axis::on_combo_changed) );
	    this->axis_box.pack_start(axis_button);
	    this->axis_box.show_all();
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

      cout << " ID=" << id << ", Axis Binding=" << name << endl;
    }
  }
  else
    cout << "invalid iter" << endl;
}

Axis::Axis(std::string label, std::string description)
: Axis()
{
	this->axis_label.set_label(label);
	this->axis_dropdown.set_active_id(description);
}
