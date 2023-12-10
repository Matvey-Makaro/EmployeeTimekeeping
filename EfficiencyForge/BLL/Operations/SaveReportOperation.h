#pragma once

#include "App/DataPool.h"
#include "Entities/Report/Report.h"
#include "IOperation.h"

class SaveReportOperation : public IOperation
{
public:
    SaveReportOperation();

    QString GetOperationName() const override;
    ICommandRunnerShp AcceptOperationVisitor(IOperationVisitor&) override;

    ReportShp GetReport() const;
    void SetReport(const ReportShp& report);

    DataPoolShp GetDataPool() const;
    void SetDataPool(const DataPoolShp& dataPool);

private:
    ReportShp _report;
    DataPoolShp _dataPool;

};
using SaveReportOperationShp = QSharedPointer<SaveReportOperation>;
