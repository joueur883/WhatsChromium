#include "MenuBar.h"

#include <QList>

MenuBar::MenuBar() {
    browserMenu = new QMenu("Browser");

    clearCacheStorageAction = new QAction("Clear cache and storage");

    connect(clearCacheStorageAction, &QAction::triggered, this, [&] {
        emit clearCacheStorageTriggered();
    });

    browserMenu->addAction(clearCacheStorageAction);

    addMenu(browserMenu);
}
