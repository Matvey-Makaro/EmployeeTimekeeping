#pragma once

#include <QObject>
#include <QSharedPointer>
#include "Utils/Loggers/ILogger.h"

class ICommand : public QObject
{
    Q_OBJECT
public:
    using QObject::QObject;
    virtual ~ICommand() = default;

    virtual bool Validate() = 0;
    virtual void Do() = 0;
    virtual void WriteLog(ILogger&) = 0;

signals:
    void Finished();
    void Failed();
};

using ICommandShp = QSharedPointer<ICommand>;
