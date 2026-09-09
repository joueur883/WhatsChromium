#pragma once

#include <QWidget>
#include <QVBoxLayout>

#include "WebView.h"

class CentralWidget : public QWidget {
    Q_OBJECT
public:
    explicit CentralWidget();

    WebView *getWebView();

private:
    QVBoxLayout *mainLayout;

    WebView *webView;
};
