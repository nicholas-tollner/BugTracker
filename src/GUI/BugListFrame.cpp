//
// Created by Nickt on 18/07/2022.
//

#include <iostream>
#include "BugListFrame.h"
#include "MainWindow.h"

BugListFrame::BugListFrame()
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
    add(scrollPane);
}

BugListFrame::~BugListFrame()
{

}

void BugListFrame::setupListView()
{
    refListStore = Gtk::ListStore::create(m_Columns);

    treeView.set_model(refListStore);
    treeView.append_column("ID", m_Columns.id);
    treeView.append_column("Title", m_Columns.title);
    int col_count = treeView.append_column("Mark", m_Columns.mark);

    // Expand columns to take up available space
    for (int i = 0; i < col_count; i++)
    {
        treeView.get_column(i)->set_expand(true);
    }
}

Glib::RefPtr<Gtk::ListStore> BugListFrame::get_list_store()
{
    return refListStore;
}

ModelColumns& BugListFrame::get_m_columns()
{
    return m_Columns;
}

Gtk::TreeView& BugListFrame::get_tree_view()
{
    return treeView;
}

// Clears List Store
void BugListFrame::clear_list()
{
    treeView.collapse_all();
    refListStore.reset();
    refListStore = Gtk::ListStore::create(m_Columns);
}




