#pragma once

#include <QWebEngineProfile>
#include <QWebEngineView>

class WebEngineProfile : public QWebEngineProfile {
    Q_OBJECT
public:
    explicit WebEngineProfile(QObject *parent = nullptr);
};
