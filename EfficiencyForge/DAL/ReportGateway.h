#pragma once

#include "Utils/Loggers/ILogger.h"
#include "Entities/Report/Report.h"
#include "AbstractGateway.h"

class ReportGateway : public AbstractGateway
{
public:
    ReportGateway() = default;

    QVector<ReportShp> GetAll(ILogger* l = nullptr);
    ReportShp GetById(Id id, ILogger* l = nullptr);
    ReportShp Save(const ReportShp& report, ILogger* l = nullptr);

protected:
    ReportShp Update(const ReportShp& report, ILogger* l = nullptr);
    ReportShp Insert(const ReportShp& report, ILogger* l = nullptr);

    static QString GetSelectByIdQuery();
    static QString GetSelectAllQuery();
    static QString GetUpdateQuery();
    static QString GetInsertQuery();
    QStringList GetColumnNames() const override;
    ReportShp ExtractReport(ILogger* l = nullptr);
};
using ReportGatewayShp = QSharedPointer<ReportGateway>;
