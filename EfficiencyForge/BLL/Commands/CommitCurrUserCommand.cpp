#include "CommitCurrUserCommand.h"


bool CommitCurrUserCommand::Validate()
{
    if(_ctx.isNull())
        return false;
    if(_dataPool.isNull())
        return false;
    return true;
}

void CommitCurrUserCommand::Do()
{
    auto& users = _ctx->users;
    if(!users.empty())
        _dataPool->SetCurrUser(users.first());
}

void CommitCurrUserCommand::SetFindUsersCtx(const FindUsersContextShp& ctx)
{
    _ctx = ctx;
}

void CommitCurrUserCommand::SetDataPool(const DataPoolShp& dataPool)
{
    _dataPool = dataPool;
}

