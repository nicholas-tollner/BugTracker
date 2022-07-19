//
// Created by Nickt on 19/07/2022.
//

#ifndef WINDOWS_GUI_APPLICATION_MODELCOLUMNS_H
#define WINDOWS_GUI_APPLICATION_MODELCOLUMNS_H

#include <gtkmm/treemodelcolumn.h>

class ModelColumns : public Gtk::TreeModelColumnRecord {
public:
    ModelColumns();
    virtual ~ModelColumns();

    Gtk::TreeModelColumn<Glib::ustring> id;
    Gtk::TreeModelColumn<Glib::ustring> title;
    Gtk::TreeModelColumn<Glib::ustring> mark;
    Gtk::TreeModelColumn<Glib::ustring> text;
};


#endif //WINDOWS_GUI_APPLICATION_MODELCOLUMNS_H
