#include "FindUserByLoginPasswordCommand.h"

bool FindUserByLoginPasswordCommand::Validate()
{
    if(_ctx.isNull())
        return false;
    return true;
}

void FindUserByLoginPasswordCommand::Do()
{
    UserGateway gateway;
    auto user = gateway.GetUserByLoginPassword(_login, _password, &_logger);
    if(_logger.HasCriticals())
    {
        emit Failed();
        return;
    }
    if(user)
        _ctx->users.push_back(user);

    emit Finished();
}

void FindUserByLoginPasswordCommand::SetFindUsersCtx(const FindUsersContextShp& ctx)
{
    _ctx = ctx;
}

void FindUserByLoginPasswordCommand::SetLogin(const QString& value)
{
    _login = value;
}

void FindUserByLoginPasswordCommand::SetPassword(const QString& value)
{
    _password = value;
}
