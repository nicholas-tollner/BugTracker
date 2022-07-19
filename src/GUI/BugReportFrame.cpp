//
// Created by Nickt on 18/07/2022.
//

#include "BugReportFrame.h"

BugReportFrame::BugReportFrame()
{
    // Setup Frame
    set_shadow_type(Gtk::SHADOW_ETCHED_IN);
    set_label("Bug Report");
    set_margin_left(10);
    set_margin_right(10);
    set_margin_top(10);
    set_label_align(0.01, 0.5);

    // Add widgets
    add(bugReportBox);
}

BugReportFrame::~BugReportFrame()
{

}

BugReportBox& BugReportFrame::getBugReportBox()
{
    return bugReportBox;
}
