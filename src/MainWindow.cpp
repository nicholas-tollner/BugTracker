//
// Created by Nickt on 17/07/2022.
//

#include "MainWindow.h"

// Setup window here
MainWindow::MainWindow() : mainBox(false, 5, Gtk::PACK_SHRINK, 0)
{
    set_title("Bug Tracker");
    set_resizable(false);
    set_border_width(10);

    // Setup widget
    add(mainBox);

    show_all_children();
}

MainWindow::~MainWindow()
{

}
