#include <QApplication>

#include <QIcon>

#include "ui/MainWindow.h"

int main(int argc, char *argv[]) {
    // What's Chromium? WhatsChromium!
    QApplication a(argc, argv);

    QIcon appIcon = QIcon::fromTheme("whatsapp");
    if (!appIcon.isNull()) {
        QApplication::setWindowIcon(appIcon);
    }

    auto *mainWindow = new MainWindow();
    mainWindow->showMaximized();

    return QApplication::exec();
}
