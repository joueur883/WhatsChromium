#pragma once

#include <QWidget>
#include <QVBoxLayout>

class CentralWidget : public QWidget {
    Q_OBJECT
public:
    explicit CentralWidget();

private:
    QVBoxLayout *mainLayout;
};
