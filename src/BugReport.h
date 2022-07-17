//
// Created by Nickt on 15/07/2022.
//

#ifndef WINDOWS_GUI_APPLICATION_BUGREPORT_H
#define WINDOWS_GUI_APPLICATION_BUGREPORT_H

#include <array>
#include <string>

class BugReport
{
public:
    BugReport(std::array<char, 512> details);
    BugReport(std::array<char, 512> details, std::array<std::string, 10> &tags);
    BugReport(std::array<char, 512> details, std::array<std::string, 10> &tags, std::string &link);
    ~BugReport();

    void increment();

private:
    int mark = 1;                           // 0 = closed, 1 = open
    unsigned int ID;
    std::array<char, 512> details;
    std::array<std::string, 10> tags;
    std::string link;

    void print();
};

#endif //WINDOWS_GUI_APPLICATION_BUGREPORT_H
