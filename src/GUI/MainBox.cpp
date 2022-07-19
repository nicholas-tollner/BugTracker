//
// Created by Nickt on 17/07/2022.
//

#include "MainBox.h"

// Delegate args to super constructor
MainBox::MainBox(bool homogenous, int spacing, Gtk::PackOptions options, int padding) : Gtk::Box(Gtk::ORIENTATION_VERTICAL, spacing)
{
    // Setup MainBox
    set_homogeneous(homogenous);

    // Add widgets
    add(bugListFrame);
    add(bugReportFrame);

    show_all_children();
}

MainBox::~MainBox()
{

}

BugReportFrame& MainBox::getBugReportFrame()
{
    return bugReportFrame;
}

BugListFrame& MainBox::getBugListFrame()
{
    return bugListFrame;
}
