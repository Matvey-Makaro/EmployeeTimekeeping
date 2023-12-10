#include <QSqlError>
#include "ReportGateway.h"

namespace
{
static const QString IdFieldName = QStringLiteral("report_id");
static const QString UserIdFieldName = QStringLiteral("user_id");
static const QString DateFieldName = QStringLiteral("date");
static const QString CreationTimeFieldName = QStringLiteral("creation_time");
static const QString StartWorkingDayFieldName = QStringLiteral("start_working_day");
static const QString EndWorkingDayFieldName = QStringLiteral("end_working_day");
}

QVector<ReportShp> ReportGateway::GetAll(ILogger* l)
{
    Prepare(GetSelectAllQuery());
    if(!Exec())
    {
        if(l)
            l->WriteCritical(FromFlags::ReportGateway, CodeFlags::ExecError, _query.lastError().databaseText());
        return {};
    }

    QVector<ReportShp> result;
    result.reserve(_query.size());
    while(_query.next())
    {
       result.push_back(ExtractReport(l));
    }
    return result;
}

ReportShp ReportGateway::GetById(Id id, ILogger* l)
{
    Prepare(GetSelectByIdQuery());
    BindValue(":id", id);

    if(!Exec())
    {
        if(l)
            l->WriteCritical(FromFlags::ReportGateway, CodeFlags::ExecError, _query.lastError().databaseText());
        return {};
    }

    if(!_query.next())
    {
        if(l)
            l->WriteWarning(FromFlags::ReportGateway, CodeFlags::NotFound, "Report not found");
        return {};
    }
    return ExtractReport(l);
}

ReportShp ReportGateway::Save(const ReportShp& report, ILogger* l)
{
    if(report->GetId() == InvalidId)
        return Insert(report, l);
    return Update(report, l);
}

ReportShp ReportGateway::Update(const ReportShp& report, ILogger* l)
{
    Prepare(GetUpdateQuery());
    BindValue(":user_id", report->GetUser()->GetId());
    BindValue(":date", report->GetDate());
    BindValue(":creation_time", report->GetCreationTime());
    BindValue(":start_working_day", report->GetStartWorkingDay());
    BindValue(":end_working_day", report->GetEndWorkingDay());
    BindValue(":id", report->GetId());

    if(!Exec())
    {
        if(l)
            l->WriteCritical(FromFlags::ReportGateway, CodeFlags::ExecError, _query.lastError().databaseText());
        return {};
    }
    // TODO: Save ReportItems;

    return report;
}

ReportShp ReportGateway::Insert(const ReportShp& report, ILogger* l)
{
    Prepare(GetInsertQuery());
    BindValue(":user_id", report->GetUser()->GetId());
    BindValue(":date", report->GetDate());
    BindValue(":creation_time", report->GetCreationTime());
    BindValue(":start_working_day", report->GetStartWorkingDay());
    BindValue(":end_working_day", report->GetEndWorkingDay());

    if(!Exec())
    {
        if(l)
            l->WriteCritical(FromFlags::ReportGateway, CodeFlags::ExecError, _query.lastError().databaseText());
        return {};
    }
    // TODO: Save ReportItems;
    auto newReport = ReportShp::create(*report);
    newReport->SetId(_query.lastInsertId().toLongLong());
    return newReport;
}

QString ReportGateway::GetSelectByIdQuery()
{
    return QStringLiteral("SELECT * FROM Report WHERE report_id = :id;");
}

QString ReportGateway::GetSelectAllQuery()
{
    return QStringLiteral("SELECT * FROM Report;");
}

QString ReportGateway::GetUpdateQuery()
{
    return QStringLiteral("UPDATE Report SET "
            "user_id = :user_id, "
            "date = :date, "
            "creation_time = :creation_time, "
            "start_working_day = :start_working_day, "
            "end_working_day = :end_working_day "
            "WHERE report_id = :id;");
}

QString ReportGateway::GetInsertQuery()
{
    return QStringLiteral("INSERT INTO Report(user_id, date, creation_time, start_working_day, end_working_day) "
            "VALUES(:user_id, :date, :creation_time, :start_working_day, :end_working_day);");
}

QStringList ReportGateway::GetColumnNames() const
{
    QStringList names;
    names << IdFieldName
          << UserIdFieldName
          << DateFieldName
          << CreationTimeFieldName
          << StartWorkingDayFieldName
          << EndWorkingDayFieldName;
    return names;
}
