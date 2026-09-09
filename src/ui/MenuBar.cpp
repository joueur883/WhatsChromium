#include "MenuBar.h"

#include <QList>

MenuBar::MenuBar(QList<bool> permissions) {
    browserMenu = new QMenu("Browser");

    clearCacheStorageAction = new QAction("Clear cache and storage");

    connect(clearCacheStorageAction, &QAction::triggered, this, [&] {
        emit clearCacheStorageTriggered();
    });

    browserMenu->addAction(clearCacheStorageAction);

    permissionsMenu = new QMenu("Permissions");

    clipboardReadWritePermission = createActionWithCheckbox("Clipboard", permissions[0]);
    desktopAudioVideoCapturePermission = createActionWithCheckbox("Desktop audio/video capture", permissions[1]);
    desktopVideoCapturePermission = createActionWithCheckbox("Desktop video capture", permissions[2]);
    geolocationPermission = createActionWithCheckbox("Geolocation", permissions[3]);
    localFontsAccessPermission = createActionWithCheckbox("Local fonts", permissions[4]);
    mediaAudioCapturePermission = createActionWithCheckbox("Media audio capture", permissions[5]);
    mediaVideoCapturePermission = createActionWithCheckbox("Media video capture", permissions[6]);
    mediaAudioVideoCapturePermission = createActionWithCheckbox("Media audio/video capture", permissions[7]);
    mouseLockPermission = createActionWithCheckbox("Mouse lock", permissions[8]);
    notificationsPermission = createActionWithCheckbox("Notifications", permissions[9]);

    connect(clipboardReadWritePermission, &QAction::toggled, this, [&] {
        emit permissionChanged(QWebEnginePermission::PermissionType::ClipboardReadWrite, clipboardReadWritePermission->isChecked());
    });
    connect(desktopAudioVideoCapturePermission, &QAction::toggled, this, [&] {
        emit permissionChanged(QWebEnginePermission::PermissionType::DesktopAudioVideoCapture, desktopAudioVideoCapturePermission->isChecked());
    });
    connect(desktopVideoCapturePermission, &QAction::toggled, this, [&] {
        emit permissionChanged(QWebEnginePermission::PermissionType::DesktopVideoCapture, desktopVideoCapturePermission->isChecked());
    });
    connect(geolocationPermission, &QAction::toggled, this, [&] {
        emit permissionChanged(QWebEnginePermission::PermissionType::Geolocation, geolocationPermission->isChecked());
    });
    connect(localFontsAccessPermission, &QAction::toggled, this, [&] {
        emit permissionChanged(QWebEnginePermission::PermissionType::LocalFontsAccess, localFontsAccessPermission->isChecked());
    });
    connect(mediaAudioCapturePermission, &QAction::toggled, this, [&] {
        emit permissionChanged(QWebEnginePermission::PermissionType::MediaAudioCapture, mediaAudioCapturePermission->isChecked());
    });
    connect(mediaVideoCapturePermission, &QAction::toggled, this, [&] {
        emit permissionChanged(QWebEnginePermission::PermissionType::MediaVideoCapture, mediaVideoCapturePermission->isChecked());
    });
    connect(mediaAudioVideoCapturePermission, &QAction::toggled, this, [&] {
        emit permissionChanged(QWebEnginePermission::PermissionType::MediaAudioVideoCapture, mediaAudioVideoCapturePermission->isChecked());
    });
    connect(mouseLockPermission, &QAction::toggled, this, [&] {
        emit permissionChanged(QWebEnginePermission::PermissionType::MouseLock, mouseLockPermission->isChecked());
    });
    connect(notificationsPermission, &QAction::toggled, this, [&] {
        emit permissionChanged(QWebEnginePermission::PermissionType::Notifications, notificationsPermission->isChecked());
    });

    permissionsMenu->addAction(clipboardReadWritePermission);
    permissionsMenu->addAction(desktopAudioVideoCapturePermission);
    permissionsMenu->addAction(desktopVideoCapturePermission);
    permissionsMenu->addAction(geolocationPermission);
    permissionsMenu->addAction(localFontsAccessPermission);
    permissionsMenu->addAction(mediaAudioCapturePermission);
    permissionsMenu->addAction(mediaVideoCapturePermission);
    permissionsMenu->addAction(mediaAudioVideoCapturePermission);
    permissionsMenu->addAction(mouseLockPermission);
    permissionsMenu->addAction(notificationsPermission);

    addMenu(browserMenu);
    addMenu(permissionsMenu);
}

QAction *MenuBar::createActionWithCheckbox(QString text, bool checked) {
    auto* action = new QAction(text);
    action->setCheckable(true);
    action->setChecked(checked);
    return action;
}

void MenuBar::setPermissionChecked(QWebEnginePermission::PermissionType permission, bool checked) {
    QAction* actionToModify = nullptr;

    switch (permission) {
        case QWebEnginePermission::PermissionType::ClipboardReadWrite:
            actionToModify = clipboardReadWritePermission;
            break;
        case QWebEnginePermission::PermissionType::DesktopAudioVideoCapture:
            actionToModify = desktopAudioVideoCapturePermission;
            break;
        case QWebEnginePermission::PermissionType::DesktopVideoCapture:
            actionToModify = desktopVideoCapturePermission;
            break;
        case QWebEnginePermission::PermissionType::Geolocation:
            actionToModify = geolocationPermission;
            break;
        case QWebEnginePermission::PermissionType::LocalFontsAccess:
            actionToModify = localFontsAccessPermission;
            break;
        case QWebEnginePermission::PermissionType::MediaAudioCapture:
            actionToModify = mediaAudioCapturePermission;
            break;
        case QWebEnginePermission::PermissionType::MediaAudioVideoCapture:
            actionToModify = mediaAudioVideoCapturePermission;
            break;
        case QWebEnginePermission::PermissionType::MediaVideoCapture:
            actionToModify = mediaVideoCapturePermission;
            break;
        case QWebEnginePermission::PermissionType::MouseLock:
            actionToModify = mouseLockPermission;
            break;
        case QWebEnginePermission::PermissionType::Notifications:
            actionToModify = notificationsPermission;
            break;
        case QWebEnginePermission::PermissionType::Unsupported:
            actionToModify = nullptr;
            break;
    }

    if (actionToModify != nullptr) {
        actionToModify->setChecked(checked);
    }
}
