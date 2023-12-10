#pragma once

#include "BLL/Commands/InitContext.h"
#include <BLL/Commands/AbstractCommand.h>

class LoadAllTasksCommand : public AbstractCommand
{
public:
    LoadAllTasksCommand() = default;
    bool Validate() override;
    void Do() override;

    void SetCtx(const InitContextShp& ctx);

private:
    InitContextShp _ctx;
};
using LoadAllTasksCommandShp = QSharedPointer<LoadAllTasksCommand>;
