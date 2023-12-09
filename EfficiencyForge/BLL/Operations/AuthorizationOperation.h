#pragma once

#include <QString>
#include "Entities/User.h"
#include "App/DataPool.h"
#include "IOperation.h"

class AuthorizationOperation : public IOperation
{
public:
    AuthorizationOperation() = default;

    QString GetOperationName() const override;
    ICommandRunnerShp AcceptOperationVisitor(IOperationVisitor&) override;

    QString GetLogin() const;
    void SetLogin(const QString& login);

    QString GetPassword() const;
    void SetPassword(const QString& password);

    DataPoolShp GetDataPool() const;
    void SetDataPool(const DataPoolShp& dataPool);

private:
    QString _login;
    QString _password;
    DataPoolShp _dataPool;
};
using AuthorizationOperationShp = QSharedPointer<AuthorizationOperation>;
