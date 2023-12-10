#include "BLL/OperationDispatcherVisitor.h"
#include "SaveReportOperation.h"



QString SaveReportOperation::GetOperationName() const
{
    return QStringLiteral("SaveReportOperation");
}

ICommandRunnerShp SaveReportOperation::AcceptOperationVisitor(IOperationVisitor& v)
{
    v.Visit(this);
}

ReportShp SaveReportOperation::GetReport() const
{
    return _report;
}

void SaveReportOperation::SetReport(const ReportShp& report)
{
    _report = report;
}

DataPoolShp SaveReportOperation::GetDataPool() const
{
    return _dataPool;
}

void SaveReportOperation::SetDataPool(const DataPoolShp& dataPool)
{
    _dataPool = dataPool;
}
