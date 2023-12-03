#include "GUI/Authorization.h"
#include "AppModel.h"
#include "AppConfigurator.h"
#include "DAL/DB.h"

#include "DAL/WorkScheduleGateway.h"
#include "DAL/PositionGateway.h"
#include "DAL/DepartmentGateway.h"
#include "DAL/UserGateway.h"

AppConfigurator::AppConfigurator(AppConfigShp appConfig, QObject* parent) :
    QObject(parent),
    _appConfig(std::move(appConfig))
{}

void AppConfigurator::Run()
{
    DB::Configure(_appConfig->DbSettings);
    auto db = DB::GetInstance();
    if(!db->IsOpen())
        qFatal("No connection to the database");

    WorkScheduleGateway workScheduleGateway;
    auto workSchedule = workScheduleGateway.GetById(1);

    PositionGateway positionGateway;
    auto pos = positionGateway.GetById(1);

    DepartmentGateway departmentGateway;
    auto department = departmentGateway.GetById(1);

    UserGateway userGateway;
    auto user1 = userGateway.SelectUserByLoginPassword("Root", "root");

    double deleteLater = 0;
}

void AppConfigurator::CreateDB()
{

}

void AppConfigurator::Authorization()
{
    auto authorizationWidget = AuthorizationShp::create();
//    IAppModelShp appModel = AppModelShp::create();
    auto appModel = AppModelShp::create();

    connect(authorizationWidget.data(), &Authorization::TryingLogIn, appModel.data(), &AppModel::OnTryingLogIn);

}
