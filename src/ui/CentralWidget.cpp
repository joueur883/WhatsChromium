#include "CentralWidget.h"

#include "WebView.h"

CentralWidget::CentralWidget() {
    mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);

    auto *webView = new WebView();
    mainLayout->addWidget(webView);

    setLayout(mainLayout);
}
