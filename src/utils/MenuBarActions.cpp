#include "MenuBarActions.h"

#include <filesystem>

#include <QApplication>
#include <QMessageBox>
#include <QProcess>

void MenuBarActions::clearCacheAndStorage() {
    QMessageBox::StandardButton result = QMessageBox::question(nullptr, "Question", "This action will restart the application and log you out of your account. Proceed anyway?", QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No);

    if (result == QMessageBox::StandardButton::Yes) {
        std::filesystem::path persistentStoragePath = std::filesystem::path(std::getenv("HOME")) / ".local" / "share" / "WhatsChromium" / "storage";
        std::filesystem::path cachePath = std::filesystem::path(std::getenv("HOME")) / ".local"/ "share" / "WhatsChromium" / "cache";

        std::filesystem::remove_all(persistentStoragePath);
        std::filesystem::remove_all(cachePath);

        auto *appProcess = new QProcess();
        appProcess->setProgram(QApplication::applicationFilePath());
        appProcess->start();
        QApplication::exit();
    }
}
