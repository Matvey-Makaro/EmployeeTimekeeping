#include <QDebug>
#include "DebugLogger.h"

void DebugLogger::WriteCritical(FromFlag from, CodeFlag code, const QString& what)
{
    qDebug() << "{CRITICAL}: From: " << from << "Code: " << code << "What: " << what;
}

void DebugLogger::WriteWarning(FromFlag from, CodeFlag code, const QString& what)
{
    qDebug() << "{Warning}: From: " << from << "Code: " << code << "What: " << what;
}

void DebugLogger::WriteTrace(const QString& what)
{
    qDebug() << "{Trace}: " << "What: " << what;
}
