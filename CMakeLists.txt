cmake_minimum_required(VERSION 3.21)
project(Windows_GUI_Application)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE
        src/main.cpp
        src/GUI/MainWindow.cpp
        src/GUI/MainBox.cpp
        src/GUI/BugListFrame.cpp
        src/GUI/BugReportFrame.cpp
        src/GUI/BugReportBox.cpp src/GUI/ModelColumns.cpp src/GUI/ModelColumns.h)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE})
target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES})