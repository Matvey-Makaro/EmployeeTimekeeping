#include "BLL/IOperationVisitor.h"
#include "InitOperation.h"

QString InitOperation::GetOperationName() const
{
    return QStringLiteral("InitOperation");
}

ICommandRunnerShp InitOperation::AcceptOperationVisitor(IOperationVisitor& v)
{
    return v.Visit(this);
}

DataPoolShp InitOperation::GetDataPool() const
{
    return _dataPool;
}

void InitOperation::SetDataPool(const DataPoolShp& dataPool)
{
    _dataPool = dataPool;
}
