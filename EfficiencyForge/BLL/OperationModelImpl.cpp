#include <QDebug>
#include "OperationModelImpl.h"

OperationModelImpl::OperationModelImpl(IOperationVisitorShp v) :
    _opVisitor(std::move(v)),
    _loggers(),
    _operations()
{}

bool OperationModelImpl::DoOperation(const IOperationShp& op)
{
    if(op.isNull())
        return false;
    if(_operations.contains(op))
    {
        QString t = QString("%1: Operation: '%2' already running!").
                arg(__PRETTY_FUNCTION__).arg(op->GetOperationName());
        WriteTrace(t);
        return false;
    }

    ICommandRunnerShp runner = op->AcceptOperationVisitor(*_opVisitor);
    if(runner.isNull())
    {
        QString t = QString("%1: Operation: '%2' is not supported!").
                arg(__PRETTY_FUNCTION__).arg(op->GetOperationName());
        WriteTrace(t);
        return false;
    }
    _operations.insert(op, runner);
    connect(runner.data(), &ICommandRunner::Finished,
            this, [this, op]
    {
        QString t = QString("%1: Finished operation: '%2'").
                arg(__PRETTY_FUNCTION__).arg(op->GetOperationName());
        WriteTrace(t);
        WriteLog(_operations.value(op));
        emit Finished(op);
        _operations.remove(op);
    });

    connect(runner.data(), &ICommandRunner::Failed,
            this, [this, op](const ICommandShp&)
    {
        QString t = QString("%1: Finished operation: '%2'").
                arg(__PRETTY_FUNCTION__).arg(op->GetOperationName());
        WriteTrace(t);
        WriteLog(_operations.value(op));
        emit Failed(op);
        _operations.remove(op);
    });

    QString t = QString("%1: Start operation: '%2'").
            arg(__PRETTY_FUNCTION__).arg(op->GetOperationName());
    WriteTrace(t);
    runner->Run();
    return true;
}

void OperationModelImpl::DismissOperation(const IOperationShp&)
{
    // TODO: Impl
}

void OperationModelImpl::AddLogger(ILoggerShp l)
{
    _loggers.push_back(l);
}

void OperationModelImpl::RemoveLogger(ILoggerShp l)
{
    _loggers.removeAll(l);
}

void OperationModelImpl::WriteTrace(const QString& trace)
{
    qDebug() << trace;
}

void OperationModelImpl::WriteLog(const ICommandRunnerShp& r)
{
    for(auto& l : qAsConst(_loggers))
        r->WriteLog(*l);
}
