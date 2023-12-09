#pragma once

#include <QObject>
#include <QSharedPointer>
#include <BLL/IOperationModel.h>
#include "Entities/User.h"
#include "DataPool.h"
#include "GUI/Authorization.h"
#include "GUI/MainWindow.h"

class AppController : public QObject
{
    Q_OBJECT
public:
    AppController(IOperationModelShp opModel,
             DataPoolShp dataPool,
             QObject* parent = nullptr);
    ~AppController() = default;


signals:
    void LogInFinished(const UserShp&);

public slots:
    void OnTryingLogIn(const QString& login, const QString& password);
    void OnCurrUserChanged(const UserShp& u);

protected slots:
    void OnLogInFinished(const UserShp& user);

private:
    void ConnectWithDataPool() const;
    void ConnectWithAuthorizationWidget() const;
    void Start();

private:
    IOperationModelShp _opModel;
    DataPoolShp _dataPool;
    AuthorizationShp _authorizationWidget;
    MainWindowShp _mainWindow;
};

using AppModelShp = QSharedPointer<AppController>;
