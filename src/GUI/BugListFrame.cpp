//
// Created by Nickt on 18/07/2022.
//

#include "BugListFrame.h"

BugListFrame::BugListFrame() : listView(3)
{
    // Setup Frame
    set_shadow_type(Gtk::SHADOW_ETCHED_IN);
    set_label("Bug List");
    set_margin_left(10);
    set_margin_right(10);
    set_margin_top(10);
    set_label_align(0.01, 0.5);

    // Setup Scroll Pane
    scrollPane.set_size_request(-1, 300);
    scrollPane.set_margin_top(10);
    scrollPane.set_margin_bottom(10);
    scrollPane.set_margin_left(10);
    scrollPane.set_margin_right(10);
    scrollPane.add(listView);
    add(scrollPane);

}

BugListFrame::~BugListFrame()
{

}
