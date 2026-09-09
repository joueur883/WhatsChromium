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

    void setupPage();

protected:
    QWebEngineView *createWindow(QWebEnginePage::WebWindowType type) override;

private:
    QWebEnginePage *page;
    WebEngineProfile *profile;
};
