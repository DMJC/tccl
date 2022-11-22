#include "device_box.h"
#include <iostream>

void Device_Box::on_button_toggled()
{
  string model = this->buffer;
  model.erase(this->buffer.size()-4);
  model.erase(0, 7);
  std::cout << "Device ID: " << model << " Device: " << this->device_number << " Toggled: "<< (m_button.get_active() ? "true" : "false") << std::endl;
}
