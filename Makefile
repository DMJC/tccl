all:
	g++ -std=c++11 main.cpp main_window.cpp device_box.cpp devices/pendular_rudder.cpp devices/tflight_hotas.cpp \
	devices/tflight_rudder.cpp devices/warthog_stick.cpp devices/warthog_throttle.cpp \
	-o tllc `pkg-config --libs --cflags gtkmm-3.0 libudev`
clean:
	rm tllc
