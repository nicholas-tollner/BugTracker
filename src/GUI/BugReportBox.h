//
// Created by Nickt on 18/07/2022.
//

#ifndef WINDOWS_GUI_APPLICATION_BUGREPORTBOX_H
#define WINDOWS_GUI_APPLICATION_BUGREPORTBOX_H

#include <gtkmm/box.h>
#include <gtkmm/frame.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/textview.h>
#include <gtkmm/textbuffer.h>

class BugReportBox : public Gtk::Box {
public:
    BugReportBox();
    virtual ~BugReportBox();

    Glib::RefPtr<Gtk::TextBuffer> getDetails();
    Gtk::Button& get_save_button();
    Gtk::Button& get_solve_button();
    Gtk::Button& get_close_button();
    Gtk::Button& get_open_button();

private:
    Gtk::Box v_box, h_box1;
    Gtk::Frame detailsFrame;
    Gtk::Button closeButton, solveButton, saveButton, openButton, deleteButton, renameButton;
    Gtk::ScrolledWindow scrollPane;
    Gtk::TextView textView;
};


#endif //WINDOWS_GUI_APPLICATION_BUGREPORTBOX_H
