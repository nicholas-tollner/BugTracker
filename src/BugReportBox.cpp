//
// Created by Nickt on 18/07/2022.
//

#include "BugReportBox.h"

BugReportBox::BugReportBox() : idLabel("ID:"), closeButton("Mark Closed"), solveButton("Mark Solved")
{
    // Setup Box
    set_orientation(Gtk::ORIENTATION_VERTICAL);

    // Setup Frames
    detailsFrame.set_label("Details:");
    screenshotFrame.set_label("Screenshot:");

    // Setup v_box, h_box1, h_box2
    v_box.set_orientation(Gtk::ORIENTATION_VERTICAL);
    h_box1.pack_start(idLabel, Gtk::PACK_SHRINK);
    h_box1.pack_end(closeButton, Gtk::PACK_SHRINK);
    h_box2.pack_end(solveButton, Gtk::PACK_SHRINK);

    // Add widgets
    v_box.add(h_box1);
    v_box.add(h_box2);
    add(v_box);
    add(detailsFrame);
    add(screenshotFrame);
}

BugReportBox::~BugReportBox()
{

}
