#include <QDebug>
#include "BLL/Operations/AuthorizationOperation.h"
#include "AppController.h"

AppController::AppController(IOperationModelShp opModel, DataPoolShp dataPool, QObject* parent) :
    QObject(parent),
    _opModel(std::move(opModel)),
    _dataPool(std::move(dataPool)),
    _authorizationWidget(AuthorizationShp::create()),
    _mainWindow()
{
    ConnectWithDataPool();
    ConnectWithAuthorizationWidget();
    Start();
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
    _mainWindow = MainWindowShp::create(user);
    _mainWindow->show();
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

