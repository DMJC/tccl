all:
	g++ -std=c++11 main.cpp main_window.cpp device_box.cpp -o tllc `pkg-config --libs --cflags gtkmm-3.0 libudev`
clean:
	rm tllc
