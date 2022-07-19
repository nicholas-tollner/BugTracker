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
#include "ModelColumns.h"

class BugListFrame : public Gtk::Frame {
public:
    BugListFrame();
    virtual ~BugListFrame();

    Gtk::TreeView& getTree();

private:
    Gtk::ScrolledWindow scrollPane;
    Gtk::TreeView treeView;
    ModelColumns m_Columns;

    Gtk::TreeModel::iterator itr;

    void setupListView();
    void testAddListView();
};


#endif //WINDOWS_GUI_APPLICATION_BUGLISTFRAME_H
