#include <iostream>
#include <gtkmm.h>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv);

    MainWindow mainWindow;
    mainWindow.set_default_size(1200, 800);

    // Widgets (Buttons, text boxes etc .. ) are contained within windows
    // Widgets are arranged inside container widgets (frames, notebooks)
    // Some widgets such as Gtk::Grid are not visible and exist to arrange other widgets

    return app->run(mainWindow);
}
