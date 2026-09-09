#include "MainWindow.h"

#include "../utils/MenuBarActions.h"

MainWindow::MainWindow() {
    setContentsMargins(0, 0, 0, 0);
    centralWidget = new CentralWidget();
    setCentralWidget(centralWidget);

    auto *view = centralWidget->getWebView();
    QList<bool> permissions = {
        view->isGranted(QWebEnginePermission::PermissionType::ClipboardReadWrite),
        view->isGranted(QWebEnginePermission::PermissionType::DesktopAudioVideoCapture),
        view->isGranted(QWebEnginePermission::PermissionType::DesktopVideoCapture),
        view->isGranted(QWebEnginePermission::PermissionType::Geolocation),
        view->isGranted(QWebEnginePermission::PermissionType::LocalFontsAccess),
        view->isGranted(QWebEnginePermission::PermissionType::MediaAudioCapture),
        view->isGranted(QWebEnginePermission::PermissionType::MediaVideoCapture),
        view->isGranted(QWebEnginePermission::PermissionType::MediaAudioVideoCapture),
        view->isGranted(QWebEnginePermission::PermissionType::MouseLock),
        view->isGranted(QWebEnginePermission::PermissionType::Notifications),
    };

    menuBar = new MenuBar(permissions);
    setMenuBar(menuBar);

    connect(menuBar, &MenuBar::clearCacheStorageTriggered, this, [&] {
        MenuBarActions::clearCacheAndStorage();
    });
    connect(menuBar, &MenuBar::permissionChanged, this, [&](QWebEnginePermission::PermissionType permission, bool granted) {
        WebView *view = centralWidget->getWebView();
        if (view != nullptr) {
            if (granted) {
                view->grantPermission(permission);
            } else {
                view->denyPermission(permission);
            }
        }
    });
}
