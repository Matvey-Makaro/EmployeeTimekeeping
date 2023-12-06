#pragma once

#include <QSharedPointer>
#include <QHash>
#include <QList>
#include "Utils/Loggers/ILogger.h"
#include "Operations/IOperation.h"
#include "ICommandRunner.h"
#include "IOperationVisitor.h"
#include "IOperationModel.h"

class OperationModelImpl : public IOperationModel
{
public:
    OperationModelImpl(IOperationVisitorShp v);
    ~OperationModelImpl() = default;

    bool DoOperation(const IOperationShp&) override;
    void DismissOperation(const IOperationShp&) override;

    void AddLogger(ILoggerShp l);
    void RemoveLogger(ILoggerShp l);

private:
    void WriteTrace(const QString&);
    void WriteLog(const ICommandRunnerShp& r);

private:
    IOperationVisitorShp _opVisitor;
    QList<ILoggerShp> _loggers;
    QHash<IOperationShp, ICommandRunnerShp> _operations;
};
using OperationModelImplShp = QSharedPointer<OperationModelImpl>;
