#include "WebView.h"

#include <iostream>
#include <QUrl>
#include <QMessageBox>

WebView::WebView() {
    profile = new WebEngineProfile(this);
    page = new QWebEnginePage(profile);
    setupPage();

    setPage(page);
    setUrl(QUrl("https://web.whatsapp.com/"));
}

WebView::WebView(WebEngineProfile *profile) {
    this->profile = profile;
    page = new QWebEnginePage(profile);
    setupPage();

    setPage(page);
    setUrl(QUrl("https://web.whatsapp.com/"));
}

WebView::~WebView() {
    setPage(nullptr);
    if (page) {
        page->deleteLater();
        page = nullptr;
    }
    if (profile) {
        profile->deleteLater();
        profile = nullptr;
    }
}

QWebEngineView *WebView::createWindow(QWebEnginePage::WebWindowType type) {
    auto *view = new WebView(profile);
    view->showMaximized();
    return view;
}

void WebView::setupPage() {
    connect(page, &QWebEnginePage::permissionRequested, this, [this](QWebEnginePermission permission) {
        QString permissionName;

        switch (permission.permissionType()) {
            case QWebEnginePermission::PermissionType::ClipboardReadWrite:
                permissionName = "Clipboard";
                break;
            case QWebEnginePermission::PermissionType::DesktopAudioVideoCapture:
                permissionName = "Desktop audio/video capture";
                break;
            case QWebEnginePermission::PermissionType::DesktopVideoCapture:
                permissionName = "Desktop video capture";
                break;
            case QWebEnginePermission::PermissionType::Geolocation:
                permissionName = "Geolocation";
                break;
            case QWebEnginePermission::PermissionType::LocalFontsAccess:
                permissionName = "Local font";
                break;
            case QWebEnginePermission::PermissionType::MediaAudioCapture:
                permissionName = "Media audio/capture";
                break;
            case QWebEnginePermission::PermissionType::MediaAudioVideoCapture:
                permissionName = "Media audio/video capture";
                break;
            case QWebEnginePermission::PermissionType::MediaVideoCapture:
                permissionName = "Media video capture";
                break;
            case QWebEnginePermission::PermissionType::MouseLock:
                permissionName = "Mouse lock";
                break;
            case QWebEnginePermission::PermissionType::Notifications:
                permissionName = "Notifications";
                break;
            case QWebEnginePermission::PermissionType::Unsupported:
                return;
        }

        QMessageBox::StandardButton result = QMessageBox::question(this, "Permission requested",
            QString("Allow %1 access?").arg(permissionName), QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No);

        if (result == QMessageBox::StandardButton::Yes) {
            permission.grant();
        } else {
            permission.deny();
        }
    });
}
