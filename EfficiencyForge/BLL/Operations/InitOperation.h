#pragma once

#include <QSharedPointer>
#include "App/DataPool.h"
#include "IOperation.h"

class InitOperation : public IOperation
{
public:
    InitOperation() = default;

    QString GetOperationName() const override;
    ICommandRunnerShp AcceptOperationVisitor(IOperationVisitor&) override;

    DataPoolShp GetDataPool() const;
    void SetDataPool(const DataPoolShp& dataPool);

private:
    DataPoolShp _dataPool;
};
using InitOperationShp = QSharedPointer<InitOperation>;
