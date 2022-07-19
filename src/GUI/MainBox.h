//
// Created by Nickt on 17/07/2022.
//

#ifndef WINDOWS_GUI_APPLICATION_MAINBOX_H
#define WINDOWS_GUI_APPLICATION_MAINBOX_H

#include <iostream>
#include <gtkmm/frame.h>
#include <gtkmm/box.h>
#include "BugListFrame.h"
#include "BugReportFrame.h"

class MainBox : public Gtk::Box {
public:
    MainBox(bool homogenous, int spacing, Gtk::PackOptions options, int padding = 0);
    virtual ~MainBox();

    BugReportFrame& getBugReportFrame();
    BugListFrame& getBugListFrame();

private:
    BugListFrame bugListFrame;
    BugReportFrame bugReportFrame;
};

#endif //WINDOWS_GUI_APPLICATION_MAINBOX_H
