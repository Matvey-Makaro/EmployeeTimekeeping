#include "CommitInitCommand.h"

bool CommitInitCommand::Validate()
{
    return !(_ctx.isNull() || _dataPool.isNull());
}

void CommitInitCommand::Do()
{
    _dataPool->SetReportItemTypes(_ctx->_reportItemTypes);
    emit Finished();
}

void CommitInitCommand::SetCtx(const InitContextShp& ctx)
{
    _ctx = ctx;
}

void CommitInitCommand::SetDataPool(const DataPoolShp& dataPool)
{
    _dataPool = dataPool;
}
