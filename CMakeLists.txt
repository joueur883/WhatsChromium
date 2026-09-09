cmake_minimum_required(VERSION 4.3)
project(WhatsChromium)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        WebEngineWidgets
        REQUIRED)

add_executable(WhatsChromium src/main.cpp
        src/ui/MainWindow.cpp
        src/ui/MainWindow.h
        src/ui/CentralWidget.cpp
        src/ui/CentralWidget.h
        src/ui/WebView.cpp
        src/ui/WebView.h
        src/utils/WebEngineProfile.cpp
        src/utils/WebEngineProfile.h
        src/ui/MenuBar.cpp
        src/ui/MenuBar.h
        src/utils/MenuBarActions.cpp
        src/utils/MenuBarActions.h)
target_link_libraries(WhatsChromium
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::WebEngineWidgets
)

