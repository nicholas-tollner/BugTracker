//
// Created by Nickt on 18/07/2022.
//

#include "BugListFrame.h"

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

Gtk::TreeView& BugListFrame::getTree()
{
    return treeView;
}

void BugListFrame::setupListView()
{
    Glib::RefPtr<Gtk::ListStore> refListStore = Gtk::ListStore::create(m_Columns);

    treeView.set_model(refListStore);
    treeView.append_column("ID", m_Columns.id);
    treeView.append_column("Title", m_Columns.title);
    treeView.append_column("Mark", m_Columns.mark);

    Gtk::TreeModel::Row row = *(refListStore->append());

    row[m_Columns.id] = "0001";
    row[m_Columns.title] = "Test Bug";
    row[m_Columns.mark] = "Open";

    row = *(refListStore->append());
    row[m_Columns.id] = "0002";
    row[m_Columns.title] = "Bad Bug";
    row[m_Columns.mark] = "Solved";

    row = *(refListStore->append());
    row[m_Columns.id] = "0003";
    row[m_Columns.title] = "Horrible Bug";
    row[m_Columns.mark] = "Closed";
}



