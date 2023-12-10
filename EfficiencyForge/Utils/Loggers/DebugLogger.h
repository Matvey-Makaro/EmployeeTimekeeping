#pragma once

#include <QSharedPointer>
#include "ILogger.h"

class DebugLogger : public ILogger
{
public:
    DebugLogger() = default;

    void WriteCritical(FromFlag from, CodeFlag code, const QString& what) override;
    void WriteWarning(FromFlag from, CodeFlag code, const QString& what) override;
    void WriteTrace(const QString& what) override;
};
using DebugLoggerShp = QSharedPointer<DebugLogger>;
