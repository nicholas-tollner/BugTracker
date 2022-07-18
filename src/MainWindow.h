//
// Created by Nickt on 17/07/2022.
//

#ifndef WINDOWS_GUI_APPLICATION_WINDOW_H
#define WINDOWS_GUI_APPLICATION_WINDOW_H

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include "MainBox.h"

class MainWindow : public Gtk::Window {
public:
    MainWindow();
    virtual ~MainWindow();

private:
    // Child widgets
    MainBox mainBox;
};


#endif //WINDOWS_GUI_APPLICATION_WINDOW_H
