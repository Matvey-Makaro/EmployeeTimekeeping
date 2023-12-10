#include "SaveReportCommand.h"



bool SaveReportCommand::Validate()
{
    return !(_report.isNull() || _dataPool.isNull());
}

void SaveReportCommand::Do()
{

}

void SaveReportCommand::SetReport(const ReportShp& report)
{
    _report = report;
}

void SaveReportCommand::SetDataPool(const DataPoolShp& dataPool)
{
    _dataPool = dataPool;
}
