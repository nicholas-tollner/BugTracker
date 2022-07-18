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

class BugListFrame : public Gtk::Frame {
public:
    BugListFrame();
    virtual ~BugListFrame();

private:
    Gtk::ScrolledWindow scrollPane;
    Gtk::ListViewText listView;
};


#endif //WINDOWS_GUI_APPLICATION_BUGLISTFRAME_H
