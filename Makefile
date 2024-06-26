all:
	g++ -std=c++11 main.cpp axis_box.cpp axis.cpp main_window.cpp binding_window.cpp joy_button_box.cpp joy_button.cpp device_box.cpp devices/pendular_rudder.cpp devices/t16000m_stick.cpp devices/twcs_throttle.cpp \
	devices/tflight_rudder.cpp devices/cougar_mfd.cpp devices/cougar_stick.cpp devices/cougar_throttle.cpp devices/warthog_stick.cpp devices/warthog_throttle.cpp \
	-o tccl `pkg-config --libs --cflags gtkmm-3.0 libudev`
clean:
	rm tccl
