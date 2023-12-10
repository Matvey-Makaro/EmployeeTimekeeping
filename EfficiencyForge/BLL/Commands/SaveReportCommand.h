#pragma once

#include "App/DataPool.h"
#include "Entities/Report/Report.h"
#include "AbstractCommand.h"

class SaveReportCommand : public AbstractCommand
{
public:
    SaveReportCommand() = default;

    bool Validate() override;
    void Do() override;

    void SetReport(const ReportShp& report);
    void SetDataPool(const DataPoolShp& dataPool);

private:
    ReportShp _report;
    DataPoolShp _dataPool;
};
using SaveReportCommandShp = QSharedPointer<SaveReportCommand>;
