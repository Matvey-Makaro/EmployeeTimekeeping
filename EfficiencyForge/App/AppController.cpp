#include <QDebug>
#include "BLL/Operations/AuthorizationOperation.h"
#include "AppController.h"

AppController::AppController(IOperationModelShp opModel, DataPoolShp dataPool, QObject* parent) :
    QObject(parent),
    _opModel(std::move(opModel)),
    _dataPool(std::move(dataPool)),
    _authorizationWidget(AuthorizationShp::create()),
    _baseMainWidget()
{
    ConnectWithDataPool();
    ConnectWithAuthorizationWidget();
    Start();
    FillDebugData();
}

void AppController::OnTryingLogIn(const QString &login, const QString &password)
{
    qDebug() << "AppModel::OnTryingLogIn()" << "login:" << login << "password:" << password;

    auto op = AuthorizationOperationShp::create();
    op->SetLogin(login);
    op->SetPassword(password);
    op->SetDataPool(_dataPool);
    _opModel->DoOperation(op);
}

void AppController::OnCurrUserChanged(const UserShp& u)
{
    if(u.isNull())
        return;
    OnLogInFinished(u);
}

void AppController::OnLogInFinished(const UserShp& user)
{
    _authorizationWidget->close();
    _baseMainWidget = BaseMainWidgetShp::create(user);
    _baseMainWidget->SetDataPool(_dataPool);
    _baseMainWidget->show();
}

void AppController::ConnectWithDataPool() const
{
    connect(_dataPool.data(), &DataPool::CurrUserChanged, this, &AppController::OnCurrUserChanged);
}

void AppController::ConnectWithAuthorizationWidget() const
{
    connect(_authorizationWidget.data(), &Authorization::TryingLogIn,
            this, &AppController::OnTryingLogIn);
}

void AppController::Start()
{
    _authorizationWidget->show();
}

void AppController::FillDebugData()
{
    auto itemType1 = ReportItemTypeShp::create(1);
    itemType1->SetName("Разработка");
    itemType1->SetIsWorkingTime(true);

    auto itemType2 = ReportItemTypeShp::create(2);
    itemType2->SetName("Обед");
    itemType2->SetIsWorkingTime(false);

    _dataPool->SetReportItemTypes({itemType1, itemType2});
}

