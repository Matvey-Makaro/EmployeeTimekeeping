#include <QSqlQuery>
#include <QSqlError>
#include "ReportItemTypeGateway.h"

namespace
{
static const QString IdFieldName = QStringLiteral("report_item_type_id");
static const QString NameFieldName = QStringLiteral("name");
static const QString IsWorkingTimeFieldName = QStringLiteral("is_working_time");
}

QVector<ReportItemTypeShp> ReportItemTypeGateway::GetAll(ILogger* l)
{
    Prepare(GetSelectAllQuery());
    if(!Exec())
    {
        if(l)
            l->WriteCritical(FromFlags::ReportItemTypeGateway, CodeFlags::ExecError, _query.lastError().databaseText());
        return {};
    }

    QVector<ReportItemTypeShp> result;
    result.reserve(_query.size());
    while(_query.next())
    {
       result.push_back(ExtractReportItemType());
    }
    return result;
}

ReportItemTypeShp ReportItemTypeGateway::GetById(Id id, ILogger* l)
{
    Prepare(GetSelectByIdQuery());
    BindValue(":id", id);

    if(!Exec())
    {
        if(l)
            l->WriteCritical(FromFlags::ReportItemTypeGateway, CodeFlags::ExecError, _query.lastError().databaseText());
        return {};
    }

    if(!_query.next())
    {
        if(l)
            l->WriteWarning(FromFlags::ReportItemTypeGateway, CodeFlags::NotFound, "ReportItemType not found");
        return {};
    }
    return ExtractReportItemType();
}

QString ReportItemTypeGateway::GetSelectByIdQuery()
{
    return QStringLiteral("SELECT * FROM ReportItemType WHERE report_item_type_id = :id;");
}

QString ReportItemTypeGateway::GetSelectAllQuery()
{
    return QStringLiteral("SELECT * FROM ReportItemType;");
}

QStringList ReportItemTypeGateway::GetColumnNames() const
{
    QStringList names;
    names << IdFieldName
          << NameFieldName
          << IsWorkingTimeFieldName;
    return names;
}

ReportItemTypeShp ReportItemTypeGateway::ExtractReportItemType()
{
    Id id = GetValueByName(IdFieldName).toLongLong();
    auto itemType = ReportItemTypeShp::create(id);
    itemType->SetName(GetValueByName(NameFieldName).toString());
    itemType->SetIsWorkingTime(GetValueByName(IsWorkingTimeFieldName).toBool());
    return itemType;
}
