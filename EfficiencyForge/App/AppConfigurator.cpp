#include "AppConfigurator.h"
#include "DAL/DB.h"

#include "DAL/WorkScheduleGateway.h"
#include "DAL/PositionGateway.h"
#include "DAL/DepartmentGateway.h"
#include "DAL/UserGateway.h"

#include "BLL/OperationDispatcherVisitor.h"
#include "BLL/OperationModelImpl.h"
#include "BLL/Operations/AuthorizationOperation.h"

#include "Utils/Loggers/DebugLogger.h"

#include "App/DataPool.h"

AppConfigurator::AppConfigurator(AppConfigShp appConfig, QObject* parent) :
    QObject(parent),
    _appConfig(std::move(appConfig))
{}

void AppConfigurator::Run()
{
    CreateDB();

    IOperationVisitorShp opVisitor = OperationDispatcherVisitorShp::create();
    auto operationModel = OperationModelImplShp::create(opVisitor);
    operationModel->AddLogger(DebugLoggerShp::create());
    _appModel = AppModelShp::create(operationModel,
                                    DataPoolShp::create());

//    Authorization();
}

void AppConfigurator::CreateDB()
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
    auto user1 = userGateway.GetUserByLoginPassword("Root", "root");

    double deleteLater = 0;
}

void AppConfigurator::Authorization()
{
    _authorizationWidget = AuthorizationShp::create();
    connect(_authorizationWidget.data(), &Authorization::TryingLogIn, _appModel.data(), &AppController::OnTryingLogIn);

    _authorizationWidget->show();
}
