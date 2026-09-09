#include "CentralWidget.h"

CentralWidget::CentralWidget() {
    mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);

    webView = new WebView();
    mainLayout->addWidget(webView);

    setLayout(mainLayout);
}

WebView *CentralWidget::getWebView() {
    return webView;
}
