//
// Created by Nickt on 17/07/2022.
//

#include "MainWindow.h"

MainWindow::MainWindow() : mainBox(false, 5, Gtk::PACK_SHRINK, 0)
{
    set_title("Bug Tracker");
    set_resizable(false);
    set_border_width(10);

    m_refActionGroup = Gio::SimpleActionGroup::create();
    m_refActionGroup->add_action("import", sigc::mem_fun(*this, &MainWindow::on_action_file_import));
    m_refActionGroup->add_action("save", sigc::mem_fun(*this, &MainWindow::on_action_file_save));

    insert_action_group("nav", m_refActionGroup);

    m_refBuilder = Gtk::Builder::create();

    // Layout actions in menubar
    Glib::ustring ui_info =
            "<interface>"
            "  <menu id='menubar'>"
            "    <submenu>"
            "      <attribute name='label' translatable='yes'>_File</attribute>"
            "      <section>"
            "        <item>"
            "          <attribute name='label' translatable='yes'>_Import</attribute>"
            "          <attribute name='action'>nav.import</attribute>"
            "        </item>"
            "        <item>"
            "          <attribute name='label' translatable='yes'>_Save</attribute>"
            "          <attribute name='action'>nav.save</attribute>"
            "        </item>"
            "      </section>"
            "    </submenu>"
            "  </menu>"
            "</interface>";

    try {
        m_refBuilder->add_from_string(ui_info);
    } catch (const Glib::Error& ex)
    {
        std::cerr << "Building menu failed : " << ex.what();
    }

    // Get menubar
    auto object = m_refBuilder->get_object("menubar");
    auto gmenu = Glib::RefPtr<Gio::Menu>::cast_dynamic(object);

    if (!gmenu)
    {
        g_warning("Gmenu not found");
    } else
    {
        auto pMenubar = Gtk::make_managed<Gtk::MenuBar>(gmenu);

        // Add menubar
        m_box.pack_start(*pMenubar, Gtk::PACK_SHRINK);
    }

    // Setup widget
    m_box.set_orientation(Gtk::ORIENTATION_VERTICAL);
    m_box.add(mainBox);
    add(m_box);

    show_all_children();
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_action_file_import()
{

}

void MainWindow::on_action_file_save()
{

}
