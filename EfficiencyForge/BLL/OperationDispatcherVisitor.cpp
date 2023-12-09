#include <QDebug>

#include "Commands/FindUserByLoginPasswordCommand.h"
#include "Commands/CommitCurrUserCommand.h"
#include "Commands/FindUsersContext.h"

#include "ChainCommandRunner.h"
#include "OperationDispatcherVisitor.h"

ICommandRunnerShp OperationDispatcherVisitor::Visit(AuthorizationOperation* op)
{
    auto ctx = FindUsersContextShp::create();
    auto findUserCmd = FindUserByLoginPasswordCommandShp::create();
    findUserCmd->SetFindUsersCtx(ctx);
    findUserCmd->SetLogin(op->GetLogin());
    findUserCmd->SetPassword(op->GetPassword());
    auto commitCmd = CommitCurrUserCommandShp::create();
    commitCmd->SetFindUsersCtx(ctx);
    commitCmd->SetDataPool(op->GetDataPool());

    auto runner = ChainCommandRunnerShp::create();
    runner->AddCommand(findUserCmd);
    runner->AddCommand(commitCmd);
    return runner;
}
