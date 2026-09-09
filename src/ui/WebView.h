#pragma once

#include <QWebEngineView>
#include <QWebEnginePage>

#include "../utils/WebEngineProfile.h"


class WebView : public QWebEngineView {
    Q_OBJECT
public:
    explicit WebView();
    explicit WebView(WebEngineProfile *profile);
    ~WebView() override;

    void grantPermission(const QWebEnginePermission::PermissionType& permission);
    void denyPermission(const QWebEnginePermission::PermissionType& permission);
    bool isGranted(const QWebEnginePermission::PermissionType& permission);

    void setupPage();

protected:
    QWebEngineView *createWindow(QWebEnginePage::WebWindowType type) override;

private:
    QWebEnginePage *page;
    WebEngineProfile *profile;
};
