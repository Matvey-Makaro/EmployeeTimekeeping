#pragma once

#include <QSharedPointer>
#include "Operations/AuthorizationOperation.h"
#include "Operations/InitOperation.h"
#include "BLL/ICommandRunner.h"

class IOperationVisitor
{
public:
    virtual ~IOperationVisitor() = default;

    virtual ICommandRunnerShp Visit(AuthorizationOperation* op) = 0;
    virtual ICommandRunnerShp Visit(InitOperation* op) = 0;
};
using IOperationVisitorShp = QSharedPointer<IOperationVisitor>;
