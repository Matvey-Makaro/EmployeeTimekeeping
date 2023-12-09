#pragma once

#include <QSharedPointer>
#include "FindUsersContext.h"
#include "App/DataPool.h"
#include "AbstractCommand.h"

class CommitCurrUserCommand : public AbstractCommand
{
public:
    CommitCurrUserCommand() = default;

    bool Validate() override;
    void Do() override;

    void SetFindUsersCtx(const FindUsersContextShp& ctx);
    void SetDataPool(const DataPoolShp& dataPool);

private:
    FindUsersContextShp _ctx;
    DataPoolShp _dataPool;
};
using CommitCurrUserCommandShp = QSharedPointer<CommitCurrUserCommand>;
