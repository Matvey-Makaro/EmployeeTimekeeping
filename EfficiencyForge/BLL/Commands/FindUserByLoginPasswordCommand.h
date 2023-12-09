#pragma once

#include <QSharedPointer>
#include <QString>
#include "DAL/UserGateway.h"
#include "FindUsersContext.h"
#include "AbstractCommand.h"

class FindUserByLoginPasswordCommand : public AbstractCommand
{
public:
    FindUserByLoginPasswordCommand() = default;

    bool Validate() override;
    void Do() override;

    void SetFindUsersCtx(const FindUsersContextShp& ctx);
    void SetLogin(const QString& value);
    void SetPassword(const QString& value);

private:
    FindUsersContextShp _ctx;
    QString _login;
    QString _password;
};
using FindUserByLoginPasswordCommandShp = QSharedPointer<FindUserByLoginPasswordCommand>;
