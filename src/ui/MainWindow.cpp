#include "MainWindow.h"

#include "../utils/MenuBarActions.h"

MainWindow::MainWindow() {
    setContentsMargins(0, 0, 0, 0);
    centralWidget = new CentralWidget();
    setCentralWidget(centralWidget);

    menuBar = new MenuBar();
    setMenuBar(menuBar);

    connect(menuBar, &MenuBar::clearCacheStorageTriggered, this, [&] {
        MenuBarActions::clearCacheAndStorage();
    });
}


