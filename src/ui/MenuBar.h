#pragma once

#include <QMenuBar>
#include <QMenu>
#include <QAction>

class MenuBar : public QMenuBar {
    Q_OBJECT
public:
    explicit MenuBar();

signals:
    void clearCacheStorageTriggered();

private:
    QMenu *browserMenu;
    QAction *clearCacheStorageAction;
};
