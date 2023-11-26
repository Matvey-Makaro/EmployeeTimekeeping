#include <QObject>
#include "GUI/Authorization.h"
#include "AppModel.h"
#include "AppConfigurator.h"

void AppConfigurator::Run()
{

}

void AppConfigurator::Authorization()
{
    auto authorizationWidget = AuthorizationShp::create();
    IAppModelShp appModel = AppModelShp::create();

//    QObject::connect(authorizationWidget.data(), &Authorization::TryingLogIn, appModel.data(), &AppModel::OnTryingLogIn);

}
