#pragma once

#include "BLL/Commands/InitContext.h"
#include "BLL/Commands/AbstractCommand.h"

class LoadAllReportItemTypesCommand : public AbstractCommand
{
public:
    LoadAllReportItemTypesCommand() = default;

    bool Validate() override;
    void Do() override;

    void SetCtx(const InitContextShp& ctx);

private:
    InitContextShp _ctx;
};
using LoadAllReportItemTypesCommandShp = QSharedPointer<LoadAllReportItemTypesCommand>;
