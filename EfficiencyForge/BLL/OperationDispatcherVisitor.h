#pragma once

#include "IOperationVisitor.h"

class OperationDispatcherVisitor : public IOperationVisitor
{
public:
    OperationDispatcherVisitor() = default;

    ICommandRunnerShp Visit(AuthorizationOperation* op) override;
};
using OperationDispatcherVisitorShp = QSharedPointer<OperationDispatcherVisitor>;
