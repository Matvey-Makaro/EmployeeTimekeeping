#pragma once

#include <QSharedPointer>
#include "BLL/ICommandRunner.h"

class IOperationVisitor;
using IOperationVisitorShp = QSharedPointer<IOperationVisitor>;

class IOperation
{
public:
    virtual ~IOperation() = default;

    virtual QString GetOperationName() const = 0;
    virtual ICommandRunnerShp AcceptOperationVisitor(IOperationVisitor&) = 0;
};
using IOperationShp = QSharedPointer<IOperation>;
