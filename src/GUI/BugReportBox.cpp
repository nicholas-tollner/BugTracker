//
// Created by Nickt on 18/07/2022.
//

#include "BugReportBox.h"

BugReportBox::BugReportBox() : closeButton("Mark Closed"), solveButton("Mark Solved"), saveButton("Save Report")
{
    // Setup Box
    set_orientation(Gtk::ORIENTATION_VERTICAL);

    // Setup Frames
    detailsFrame.set_label("Details");
    detailsFrame.set_margin_left(10);
    detailsFrame.set_margin_right(10);
    detailsFrame.set_margin_top(10);
    detailsFrame.set_margin_bottom(30);
    detailsFrame.set_label_align(0.01, 0.5);

    saveButton.set_margin_left(10);
    saveButton.set_margin_right(10);

    // Setup scrollPane, textView
    scrollPane.set_size_request(-1, 300);
    scrollPane.set_margin_top(10);
    scrollPane.set_margin_bottom(10);
    scrollPane.set_margin_left(10);
    scrollPane.set_margin_right(10);

    textView.set_wrap_mode(Gtk::WRAP_WORD_CHAR);

    // Setup v_box, h_box1, h_box2
    v_box.set_orientation(Gtk::ORIENTATION_VERTICAL);
    v_box.set_margin_left(10);
    v_box.set_margin_right(10);
    v_box.set_margin_top(10);

    h_box1.set_halign(Gtk::ALIGN_CENTER);
    h_box1.pack_start(closeButton, Gtk::PACK_SHRINK);
    h_box1.pack_start(saveButton, Gtk::PACK_SHRINK);
    h_box1.pack_start(solveButton, Gtk::PACK_SHRINK);

    // Add widgets
    scrollPane.add(textView);
    detailsFrame.add(scrollPane);

    v_box.add(h_box1);
    v_box.add(h_box2);

    add(v_box);
    add(detailsFrame);
}

BugReportBox::~BugReportBox()
{

}
