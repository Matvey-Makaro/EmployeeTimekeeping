#include "BLL/IOperationVisitor.h"
#include "AuthorizationOperation.h"

QString AuthorizationOperation::GetOperationName() const
{
    return QStringLiteral("AuthorizationOperation");
}

ICommandRunnerShp AuthorizationOperation::AcceptOperationVisitor(IOperationVisitor& v)
{
    return v.Visit(this);
}

QString AuthorizationOperation::GetLogin() const
{
    return _login;
}

void AuthorizationOperation::SetLogin(const QString& login)
{
    _login = login;
}

QString AuthorizationOperation::GetPassword() const
{
    return _password;
}

void AuthorizationOperation::SetPassword(const QString& password)
{
    _password = password;
}

DataPoolShp AuthorizationOperation::GetDataPool() const
{
    return _dataPool;
}

void AuthorizationOperation::SetDataPool(const DataPoolShp& dataPool)
{
    _dataPool = dataPool;
}
