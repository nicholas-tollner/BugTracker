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

            std::ifstream infile(dialog.get_filename());

            updateList(infile);

            attachSignals();

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

    // Enable confirmation dialog for file overwriting
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
            ofile << get_report()->get_text() << std::endl;
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
Glib::RefPtr<Gtk::TextBuffer> MainWindow::get_report()
{
    return mainBox.getBugReportFrame().getBugReportBox().getDetails();
}

void MainWindow::updateList(std::ifstream& file)
{
    if (row != nullptr)
    {
        refTreeSelection.reset();
        mainBox.getBugListFrame().clear_list();
        attachSignals();
    }

    refListStore = mainBox.getBugListFrame().get_list_store();

    // Parse file and populate fields
    std::string line;
    std::string report;
    int count = 0;

    while(std::getline(file, line))
    {
        if (line == "##" || line == "==")
        {
            if (count == 4)
            {
                row[m_Columns.text] = report;
                report.clear();
                count = 0;
            }

            if (line == "==")
            {
                break;
            }

            row = *(refListStore->append());
            count++;
            continue;
        }

        switch (count)
        {
            case 1:
            {
                row[m_Columns.id] = line;
                count++;
                break;
            }

            case 2:
            {
                row[m_Columns.title] = line;
                count++;
                break;
            }

            case 3:
            {
                row[m_Columns.mark] = line;
                count++;
                break;
            }

            case 4:
            {
                report += line;
                break;
            }

            default:
                break;
        }
    }
}

/**
 * Handles updating of textView using text contained in m_Columns.text
 */
void MainWindow::on_selection_changed()
{
    refTreeSelection = mainBox.getBugListFrame().get_tree_view().get_selection();
    row = *(refTreeSelection->get_selected());
    printRow(row);

    // Clear Gtk::TextBuffer then write to buffer
    get_report()->erase(get_report()->begin(), get_report()->end());

    auto itr = get_report()->begin();
    get_report()->insert(itr, row.get_value(m_Columns.text));
}

/**
 * Handles saving of individual bug reports
 */
void MainWindow::on_action_report_save()
{
    refTreeSelection = mainBox.getBugListFrame().get_tree_view().get_selection();
    row = *(refTreeSelection->get_selected());

    row.set_value(m_Columns.text, get_report()->get_text());
    std::cout << "Bug Report saved" << std::endl;
}

void MainWindow::on_action_update_mark(int m)
{
    refTreeSelection = mainBox.getBugListFrame().get_tree_view().get_selection();
    row = *(refTreeSelection->get_selected());

    switch (m) {
        case 0:
        {
            row.set_value(m_Columns.mark, Glib::ustring("Closed"));
            break;
        }

        case 1:
        {
            row.set_value(m_Columns.mark, Glib::ustring("Open"));
            break;
        }

        case 2:
        {
            row.set_value(m_Columns.mark, Glib::ustring("Solved"));
            break;
        }

        default:
            break;
    }
}

void MainWindow::on_action_add_row()
{
    auto row_itr = mainBox.getBugListFrame().get_list_store()->append();
    row_itr--;
    int new_id = std::stoi(row_itr->get_value(m_Columns.id).data()) + 1;
    row_itr++;
    row_itr->set_value(m_Columns.id, Glib::ustring(std::to_string(new_id)));
    row_itr->set_value(m_Columns.mark, Glib::ustring("Open"));
}

void MainWindow::attachSignals()
{
    // Attach signal to selection
    refTreeSelection = mainBox.getBugListFrame().get_tree_view().get_selection();
    refTreeSelection->signal_changed().connect(sigc::mem_fun(*this, &MainWindow::on_selection_changed));

    // Attach signals to buttons
    mainBox.getBugReportFrame().getBugReportBox().get_save_button().signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_action_report_save));
    mainBox.getBugReportFrame().getBugReportBox().get_close_button().signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_action_update_mark), 0));
    mainBox.getBugReportFrame().getBugReportBox().get_open_button().signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_action_update_mark), 1));
    mainBox.getBugReportFrame().getBugReportBox().get_solve_button().signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_action_update_mark), 2));
    mainBox.getBugListFrame().get_new_button().signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_action_add_row));
}

void MainWindow::printRow(Gtk::TreeIter itr)
{
    int row_id = std::stoi(itr->get_value(m_Columns.id).data());

    std::cout << "Row ID: " << row_id << std::endl;
}
