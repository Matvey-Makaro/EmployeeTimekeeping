#include "AccumulateLogger.h"

void AccumulateLogger::WriteCritical(FromFlag fromFlag, CodeFlag codeFlag, const QString& what)
{
    _criticals.push_back({fromFlag, codeFlag, what});
}

void AccumulateLogger::WriteWarning(FromFlag fromFlag, CodeFlag codeFlag, const QString& what)
{
    _warnings.push_back({fromFlag, codeFlag, what});
}

void AccumulateLogger::WriteTrace(const QString& what)
{
    _traces.push_back(what);
}

const QVector<AccumulateLogger::Record>& AccumulateLogger::GetCriticals() const
{
    return _criticals;
}

const QVector<AccumulateLogger::Record>& AccumulateLogger::GetWarnings() const
{
    return _warnings;
}

const QVector<QString>& AccumulateLogger::GetTraces() const
{
    return _traces;
}

bool AccumulateLogger::HasCriticals() const
{
    return !_criticals.empty();
}

bool AccumulateLogger::HasWarnings() const
{
    return !_warnings.empty();
}

bool AccumulateLogger::HasTraces() const
{
    return !_traces.empty();
}

void AccumulateLogger::Clear()
{
    _criticals.clear();
    _warnings.clear();
    _traces.clear();
}
