//
// Created by Nickt on 18/07/2022.
//

#ifndef WINDOWS_GUI_APPLICATION_BUGREPORTBOX_H
#define WINDOWS_GUI_APPLICATION_BUGREPORTBOX_H

#include <gtkmm/box.h>
#include <gtkmm/frame.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>

class BugReportBox : public Gtk::Box {
public:
    BugReportBox();
    virtual ~BugReportBox();
private:
    Gtk::Box v_box, h_box1, h_box2;
    Gtk::Frame detailsFrame, screenshotFrame;
    Gtk::Button closeButton, solveButton;
    Gtk::Label idLabel;
};


#endif //WINDOWS_GUI_APPLICATION_BUGREPORTBOX_H
