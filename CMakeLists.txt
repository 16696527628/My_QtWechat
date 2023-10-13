cmake_minimum_required(VERSION 3.20)
project(untitled3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/limingyuan/Qt/6.5.2/macos/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        REQUIRED)

add_executable(untitled3 main.cpp
        Login/loginPage_main.cpp
        Login/loginPage_main.h
        Login/login.cpp
        Login/login.h
        Login/loginPage_scan.cpp
        Login/loginPage_scan.h
        userWidget/main_widget.cpp
        userWidget/main_widget.h
        userWidget/Message/MessagePage.h
        userWidget/Message/MessagePage.cpp
        userWidget/Contact/ContactPage.cpp
        userWidget/Contact/ContactPage.h
        userWidget/PersonalPage.cpp
        userWidget/PersonalPage.h
        userWidget/SideBar.cpp
        userWidget/SideBar.h
        userWidget/Message/Buddy.cpp
        userWidget/Message/Buddy.h
        userWidget/Message/TalkPage.cpp
        userWidget/Message/TalkPage.h
        user_info.cpp
        user_info.h
        userWidget/Message/my_Line.cpp
        userWidget/Message/my_Line.h
)
target_link_libraries(untitled3
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Sql
)

