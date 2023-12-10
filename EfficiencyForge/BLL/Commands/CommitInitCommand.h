#pragma once

#include <QSharedPointer>
#include "InitContext.h"
#include "App/DataPool.h"
#include "AbstractCommand.h"

class CommitInitCommand : public AbstractCommand
{
public:
    CommitInitCommand() = default;

    bool Validate() override;
    void Do() override;

    void SetCtx(const InitContextShp& ctx);
    void SetDataPool(const DataPoolShp& dataPool);

private:
    InitContextShp _ctx;
    DataPoolShp _dataPool;
};
using CommitInitCommandShp = QSharedPointer<CommitInitCommand>;
