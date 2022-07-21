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

    void on_selection_changed();

private:
    // Child widgets
    MainBox mainBox;
    Gtk::Box m_box;
    ModelColumns m_Columns;

    bool attached = false;

    // Signal handlers
    void on_action_file_import();
    void on_action_file_save();
    void on_action_report_save();
    void on_action_update_mark(int m);
    void on_action_add_row();
    void attachSignals();
    void printRow(Gtk::TreeIter itr);

    Glib::RefPtr<Gtk::TextBuffer> get_report();

    Gtk::TreeModel::Row row;
    Glib::RefPtr<Gtk::ListStore> *refListStore = nullptr;
    Gtk::TreeView* refTreePtr = nullptr;

    // Menubar
    Glib::RefPtr<Gio::SimpleActionGroup> m_refActionGroup;
    Glib::RefPtr<Gtk::Builder> m_refBuilder;

    void updateList(std::ifstream& file);
};


#endif //WINDOWS_GUI_APPLICATION_WINDOW_H
