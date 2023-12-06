#pragma once

#include <QSharedPointer>
#include <QObject>
#include "Utils/Loggers/ILogger.h"
#include "Commands/ICommand.h"

class ICommandRunner : public QObject
{
    Q_OBJECT
public:
    using QObject::QObject;
    virtual ~ICommandRunner() = default;

    virtual void WriteLog(ILogger&) = 0;
    virtual void Run() = 0;
    virtual void Reset() = 0;

signals:
    void Failed(const ICommandShp&);
    void Finished();
};
using ICommandRunnerShp = QSharedPointer<ICommandRunner>;
