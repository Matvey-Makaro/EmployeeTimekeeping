#include "BLL/IOperationVisitor.h"
#include "AuthorizationOperation.h"



QString AuthorizationOperation::GetOperationName() const
{
    return QStringLiteral("AuthorizationOperation");
}

ICommandRunnerShp AuthorizationOperation::AcceptOperationVisitor(IOperationVisitor& v)
{
    return v.Visit(this);
}
