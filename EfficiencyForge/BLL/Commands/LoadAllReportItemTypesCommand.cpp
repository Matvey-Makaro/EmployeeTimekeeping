#include "DAL/ReportItemTypeGateway.h"
#include "LoadAllReportItemTypesCommand.h"

bool LoadAllReportItemTypesCommand::Validate()
{
    if(_ctx.isNull())
        return false;
    return true;
}

void LoadAllReportItemTypesCommand::Do()
{
    ReportItemTypeGateway gateway;
    _ctx->_reportItemTypes = gateway.GetAll(&_logger);
    emit Finished();
}

void LoadAllReportItemTypesCommand::SetCtx(const InitContextShp& ctx)
{
    _ctx = ctx;
}
