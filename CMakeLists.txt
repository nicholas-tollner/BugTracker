cmake_minimum_required(VERSION 3.21)
project(Windows_GUI_Application)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE
        src/main.cpp
        src/BugList.cpp
        src/BugReport.cpp
        src/MainWindow.cpp
        )

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(${CMAKE_PROJECT_NAME} WIN32 ${SOURCE})
target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES})