#pragma once

#include <QSharedPointer>
#include "Entities/Report/ReportItemType.h"
#include "Utils/Loggers/ILogger.h"
#include "AbstractGateway.h"

class ReportItemTypeGateway : public AbstractGateway
{
public:
    ReportItemTypeGateway() = default;

    QVector<ReportItemTypeShp> GetAll(ILogger* l = nullptr);
    ReportItemTypeShp GetById(Id id, ILogger* l = nullptr);

protected:
    static QString GetSelectByIdQuery();
    static QString GetSelectAllQuery();
    QStringList GetColumnNames() const override;
    ReportItemTypeShp ExtractReportItemType();
};
using ReportItemTypeGatewayShp = QSharedPointer<ReportItemTypeGateway>;
