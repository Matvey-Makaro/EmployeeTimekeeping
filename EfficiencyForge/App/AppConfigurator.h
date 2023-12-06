#pragma once

#include <QObject>
#include <QSharedPointer>
#include "AppConfig.h"
#include "AppModel.h"
#include "GUI/Authorization.h"

class AppConfigurator : public QObject
{
    Q_OBJECT
public:
    AppConfigurator(AppConfigShp appConfig, QObject* parent = nullptr);

    void Run();

private:
    void CreateDB();
    void Authorization();
    void MainWork();

private:
    AppConfigShp _appConfig;
    AuthorizationShp _authorizationWidget;
    AppModelShp _appModel;
};

using AppConfiguratorShp = QSharedPointer<AppConfigurator>;
