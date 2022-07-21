//
// Created by Nickt on 18/07/2022.
//

#include <iostream>
#include "BugListFrame.h"
#include "MainWindow.h"

BugListFrame::BugListFrame() : newButton("Add")
{
    // Setup Frame
    set_shadow_type(Gtk::SHADOW_ETCHED_IN);
    set_label("Bug List");
    set_margin_left(10);
    set_margin_right(10);
    set_margin_top(10);
    set_label_align(0.01, 0.5);

    // Setup Scroll Pane
    setupListView();
    treeView.set_grid_lines(Gtk::TREE_VIEW_GRID_LINES_HORIZONTAL);
    scrollPane.set_size_request(-1, 300);
    scrollPane.set_margin_top(10);
    scrollPane.set_margin_bottom(10);
    scrollPane.set_margin_left(10);
    scrollPane.set_margin_right(10);
    scrollPane.add(treeView);

    // Setup v_box, h_box
    v_box.set_orientation(Gtk::ORIENTATION_VERTICAL);
    h_box.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
    v_box.set_margin_left(10);
    v_box.set_margin_right(10);
    v_box.set_margin_top(10);
    newButton.set_margin_right(10);

    h_box.pack_end(newButton, Gtk::PACK_SHRINK);

    v_box.add(h_box);
    v_box.add(scrollPane);
    add(v_box);
}

BugListFrame::~BugListFrame()
{

}

void BugListFrame::setupListView()
{
    refListStore = Gtk::ListStore::create(m_Columns);

    treeView.set_model(refListStore);
    treeView.append_column("ID", m_Columns.id);
    treeView.append_column_editable("Title", m_Columns.title);
    int col_count = treeView.append_column("Mark", m_Columns.mark);

    // Expand columns to take up available space
    for (int i = 0; i < col_count; i++)
    {
        treeView.get_column(i)->set_expand(true);
        int width = 0;

        switch(i)
        {
            case 0:
            {
                width = 100;
                break;
            }

            case 1:
            {
                width = 500;
                break;
            }

            case 2:
            {
                width = 160;
                break;
            }

            default:
                break;
        }
        treeView.get_column(i)->set_fixed_width(width);
    }
}

Glib::RefPtr<Gtk::ListStore>* BugListFrame::get_list_store()
{
    return &refListStore;
}

Gtk::TreeView* BugListFrame::get_tree_view()
{
    return &treeView;
}

// Clears List Store
void BugListFrame::clear_list()
{
    refListStore = Gtk::ListStore::create(m_Columns);
    treeView.set_model(refListStore);
}

Gtk::Button &BugListFrame::get_new_button()
{
    return newButton;
}