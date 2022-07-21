//
// Created by Nickt on 18/07/2022.
//

#ifndef WINDOWS_GUI_APPLICATION_BUGLISTFRAME_H
#define WINDOWS_GUI_APPLICATION_BUGLISTFRAME_H

#include <gtkmm/frame.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/treeview.h>
#include <gtkmm/treemodel.h>
#include <gtkmm/listviewtext.h>
#include <gtkmm/box.h>
#include "ModelColumns.h"

class BugListFrame : public Gtk::Frame {
public:
    BugListFrame();
    virtual ~BugListFrame();

    Glib::RefPtr<Gtk::ListStore>* get_list_store();
    Gtk::TreeView* get_tree_view();
    void clear_list();
    Gtk::Button& get_new_button();

private:
    Gtk::ScrolledWindow scrollPane;
    Gtk::TreeView treeView;
    ModelColumns m_Columns;
    Gtk::Button newButton, renameButton;
    Gtk::Box v_box, h_box;

    Glib::RefPtr<Gtk::ListStore> refListStore;

    void setupListView();
};


#endif //WINDOWS_GUI_APPLICATION_BUGLISTFRAME_H
