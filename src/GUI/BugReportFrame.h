//
// Created by Nickt on 18/07/2022.
//

#ifndef WINDOWS_GUI_APPLICATION_BUGREPORTFRAME_H
#define WINDOWS_GUI_APPLICATION_BUGREPORTFRAME_H

#include <gtkmm/frame.h>
#include "BugReportBox.h"

class BugReportFrame : public Gtk::Frame {
public:
    BugReportFrame();
    virtual ~BugReportFrame();

    BugReportBox& getBugReportBox();

private:
    BugReportBox bugReportBox;
};


#endif //WINDOWS_GUI_APPLICATION_BUGREPORTFRAME_H
