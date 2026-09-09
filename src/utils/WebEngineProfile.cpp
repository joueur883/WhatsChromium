#include "WebEngineProfile.h"

#include <filesystem>

WebEngineProfile::WebEngineProfile(QObject *parent) : QWebEngineProfile("WhatsChromium", parent) {
    setHttpUserAgent(
        "Mozilla/5.0 (X11; Linux x86_64) "
        "AppleWebKit/537.36 (KHTML, like Gecko) "
        "Chrome/120.0.0.0 Safari/537.36"
        );

    setPersistentCookiesPolicy(QWebEngineProfile::PersistentCookiesPolicy::ForcePersistentCookies);

    std::filesystem::path persistentStoragePath = std::filesystem::path(std::getenv("HOME")) / ".local" / "WhatsChromium" / "storage";
    std::filesystem::path cachePath = std::filesystem::path(std::getenv("HOME")) / ".local" / "WhatsChromium" / "cache";
    std::filesystem::create_directories(persistentStoragePath);
    std::filesystem::create_directories(cachePath);

    setPersistentStoragePath(QString::fromStdString(persistentStoragePath.string()));
    setCachePath(QString::fromStdString(cachePath.string()));


}
