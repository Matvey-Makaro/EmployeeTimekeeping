#include "DAL/TaskGateway.h"
#include "LoadAllTasksCommand.h"

bool LoadAllTasksCommand::Validate()
{
    return !_ctx.isNull();
}

void LoadAllTasksCommand::Do()
{
    TaskGateway gateway;
    _ctx->tasks = gateway.GetAll(&_logger);
    emit Finished();
}

void LoadAllTasksCommand::SetCtx(const InitContextShp& ctx)
{
    _ctx = ctx;
}
