//
// Created by Nickt on 17/07/2022.
//

#include "MainWindow.h"
#include <iostream>

// Setup window here
MainWindow::MainWindow() : m_button1("Button 1"), m_button2("Button 2")
{
    set_title("Bug Tracker");
    set_resizable(false);
    set_border_width(10);

    // Setup widget
    m_button1.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_clicked));
    m_button2.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_clicked));
    m_box1.pack_start(m_button1);
    m_box1.pack_start(m_button2);

    m_button1.show();
    m_button2.show();

    add(m_box1);
    m_box1.show();

}

MainWindow::~MainWindow()
{

}

void MainWindow::on_button_clicked()
{
    std::cout << "Hello World!" << std::endl;
}
