//
// Created by Nickt on 15/07/2022.
//

#include "BugReport.h"


static unsigned int bugID = 0;

BugReport::BugReport(std::array<char, 512> details)
{
    ID = bugID;
    increment();

    this->details = details;

}

BugReport::BugReport(std::array<char, 512> details, std::array<std::string, 10> &tags) : BugReport(details)
{
    this->tags = tags;
}

BugReport::BugReport(std::array<char, 512> details, std::array<std::string, 10> &tags, std::string &link) : BugReport(details, tags)
{
    this->link = link;
}

BugReport::~BugReport()
{

}

void BugReport::print()
{

}

void BugReport::increment()
{
    bugID++;
}


