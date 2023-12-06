#pragma once

#include <QVector>
#include "ILogger.h"

class AccumulateLogger : public ILogger
{
    struct Record
    {
        FromFlag fromFlag;
        CodeFlag codeFlag;
        QString what;
    };

public:
    AccumulateLogger() = default;

    void WriteCritical(FromFlag, CodeFlag, const QString& what) override;
    void WriteWarning(FromFlag, CodeFlag, const QString& what) override;
    void WriteTrace(const QString& what) override;

    const QVector<Record>& GetCriticals() const;
    const QVector<Record>& GetWarnings() const;
    const QVector<QString>& GetTraces() const;

    bool HasCriticals() const;
    bool HasWarnings() const;
    bool HasTraces() const;

    void Clear();

private:
    QVector<Record> _criticals;
    QVector<Record> _warnings;
    QVector<QString> _traces;
};

