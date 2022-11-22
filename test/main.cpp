#include "main_window.h"

int main (int argc, char *argv[])
{
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.test");
	//Shows the window and returns when it is closed.
	Main_Window main_window;
	return app->run(main_window);
}
