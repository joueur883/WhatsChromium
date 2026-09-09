#pragma once

#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include "QWebEnginePermission"

class MenuBar : public QMenuBar {
    Q_OBJECT
public:
    explicit MenuBar(QList<bool> permissions);

    void setPermissionChecked(QWebEnginePermission::PermissionType permission, bool checked);

    QAction* createActionWithCheckbox(QString text, bool checked);

signals:
    void clearCacheStorageTriggered();
    void permissionChanged(QWebEnginePermission::PermissionType permission, bool granted);

private:
    QMenu *browserMenu;
    QAction *clearCacheStorageAction;

    QMenu *permissionsMenu;
    QAction *clipboardReadWritePermission;
    QAction *desktopAudioVideoCapturePermission;
    QAction *desktopVideoCapturePermission;
    QAction *geolocationPermission;
    QAction *localFontsAccessPermission;
    QAction *mediaAudioCapturePermission;
    QAction *mediaVideoCapturePermission;
    QAction *mediaAudioVideoCapturePermission;
    QAction *mouseLockPermission;
    QAction *notificationsPermission;
};
