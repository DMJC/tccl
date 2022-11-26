#include "main_window.h"
#include "../devices/warthog_stick.h"
#include "../devices/warthog_throttle.h"

int main (int argc, char *argv[])
{
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.test");
	//Shows the window and returns when it is closed.
	Main_Window main_window(warthog_throttle_axes());
	return app->run(main_window);
}
