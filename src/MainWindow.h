//
// Created by Nickt on 17/07/2022.
//

#ifndef WINDOWS_GUI_APPLICATION_WINDOW_H
#define WINDOWS_GUI_APPLICATION_WINDOW_H

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>

class MainWindow : public Gtk::Window {
public:
    MainWindow();
    ~MainWindow() override;


private:
    // Child widgets
    Gtk::Box m_box1;
    Gtk::Button m_button1, m_button2;

    void on_button_clicked();
};


#endif //WINDOWS_GUI_APPLICATION_WINDOW_H
