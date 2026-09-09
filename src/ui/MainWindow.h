#pragma once

#include <QMainWindow>
#include <QWidget>

#include "CentralWidget.h"
#include "MenuBar.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow();

private:
    CentralWidget *centralWidget;
    MenuBar *menuBar;
};
