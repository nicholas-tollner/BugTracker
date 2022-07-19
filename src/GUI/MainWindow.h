//
// Created by Nickt on 17/07/2022.
//

#ifndef WINDOWS_GUI_APPLICATION_WINDOW_H
#define WINDOWS_GUI_APPLICATION_WINDOW_H

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <giomm/simpleactiongroup.h>
#include <gtkmm/builder.h>
#include <gtkmm/menubar.h>
#include <gtkmm/dialog.h>
#include <gtkmm/filechooserdialog.h>
#include "MainBox.h"

class MainWindow : public Gtk::Window {
public:
    MainWindow();
    virtual ~MainWindow();

private:
    // Child widgets
    MainBox mainBox;
    Gtk::Box m_box;

    // Signal handlers
    void on_action_file_import();
    void on_action_file_save();
    Glib::RefPtr<Gtk::TextBuffer> get_report();
//    Glib::ustring get_list();

    // Menubar
    Glib::RefPtr<Gio::SimpleActionGroup> m_refActionGroup;
    Glib::RefPtr<Gtk::Builder> m_refBuilder;
};


#endif //WINDOWS_GUI_APPLICATION_WINDOW_H
