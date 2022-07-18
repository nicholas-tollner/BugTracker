//
// Created by Nickt on 18/07/2022.
//

#include "BugReportFrame.h"

BugReportFrame::BugReportFrame()
{
    // Setup Frame
    set_shadow_type(Gtk::SHADOW_ETCHED_IN);
    set_label("Bug Report");

    // Add widgets
    add(bugReportBox);
}

BugReportFrame::~BugReportFrame()
{

}
