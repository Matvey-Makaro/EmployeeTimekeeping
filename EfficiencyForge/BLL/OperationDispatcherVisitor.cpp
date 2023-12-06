#include <QDebug>
#include "ChainCommandRunner.h"
#include "OperationDispatcherVisitor.h"



ICommandRunnerShp OperationDispatcherVisitor::Visit(AuthorizationOperation* op)
{
    qDebug() << "Hello from: " << op->GetOperationName();
    return ChainCommandRunnerShp::create();
}
