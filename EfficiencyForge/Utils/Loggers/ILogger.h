#pragma once

#include <QSharedPointer>
#include <QString>
#include "Flags.h"

class ILogger
{
public:
    virtual ~ILogger() = default;

    virtual void WriteCritical(FromFlag, CodeFlag, const QString& what) = 0;
    virtual void WriteWarning(FromFlag, CodeFlag, const QString& what) = 0;
    virtual void WriteTrace(const QString& what) = 0;
};
using ILoggerShp = QSharedPointer<ILogger>;
