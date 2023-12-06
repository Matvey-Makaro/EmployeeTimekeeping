#pragma once

#include "IOperation.h"

class AuthorizationOperation : public IOperation
{
public:
    AuthorizationOperation() = default;

    QString GetOperationName() const override;
    ICommandRunnerShp AcceptOperationVisitor(IOperationVisitor&) override;
};
using AuthorizationOperationShp = QSharedPointer<AuthorizationOperation>;
