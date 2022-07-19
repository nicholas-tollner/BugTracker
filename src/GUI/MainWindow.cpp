//
// Created by Nickt on 17/07/2022.
//

#include <fstream>
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

/**
 * Invoked when user selects import from file menu
 * Handles creation and response of file chooser
 */
void MainWindow::on_action_file_import()
{
    std::cout << "Import pressed!" << std::endl;
    Gtk::FileChooserDialog dialog("Import", Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);    // Allows window manager to center dialog over main window

    // Add response buttons
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("Import", Gtk::RESPONSE_OK);

    // Filter for text files
    auto filter_text = Gtk::FileFilter::create();
    filter_text->set_name("Text Files");
    filter_text->add_mime_type("text/plain");
    dialog.add_filter(filter_text);

    // Handle dialog response from user
    int result = dialog.run();
    switch (result)
    {
        case (Gtk::RESPONSE_OK):
        {
            std::cout << "Select clicked" << "\n";
            std::cout << "File selected: " << dialog.get_filename() << std::endl;

            // TODO Parse file and update bugList

            std::ifstream infile(dialog.get_filename());


            infile.close();

            break;
        }

        case (Gtk::RESPONSE_CANCEL):
        {
            std::cout << "Cancel clicked" << std::endl;
            break;
        }

        default:
            std::cout << "Something unexpected happened!" << std::endl;
            break;
    }
}

/**
 * Invoked when user selects save from file menu
 * Handles creation and response of file chooser
 *
 * Allows user to save file
 * Provides user with confirmation window when attempting to overwrite a file
 */
void MainWindow::on_action_file_save()
{
    std::cout << "Save pressed!" << std::endl;
    Gtk::FileChooserDialog dialog("Save", Gtk::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);    // Allows window manager to center dialog over main window

    dialog.set_do_overwrite_confirmation(true);

    // Add response buttons
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("Save", Gtk::RESPONSE_OK);

    // Handle dialog response from user
    int result = dialog.run();
    switch (result)
    {
        case (Gtk::RESPONSE_OK):
        {
            std::cout << "Save clicked" << "\n";
            std::cout << "File selected: " << dialog.get_filename() << std::endl;

            std::string filename = dialog.get_filename();

            // Append .txt extension to filename if it does not already exist
            if (filename.size() < 4 || filename.substr(filename.size() - 4, std::string::npos) != ".txt")
            {
                filename += ".txt";
            }

            // Open file and write contents of text view
            std::ofstream ofile(filename);
            ofile << get_report() << std::endl;
            ofile.close();

            break;
        }

        case (Gtk::RESPONSE_CANCEL):
        {
            std::cout << "Cancel clicked" << std::endl;
            break;
        }

        default:
            std::cout << "Something unexpected happened!" << std::endl;
            break;
    }
}

// Accesses the text within the Gtk::TextBuffer used by the text view
std::string MainWindow::get_report()
{
    return mainBox.getBugReportFrame().getBugReportBox().getDetails()->get_text();
}
