#include <QVariant>
#include "DAL/DB.h"
#include "WorkScheduleGateway.h"

namespace
{
static const QString WorkScheduleIdFieldName = "work_schedule_id";
static const QString StartOfWorkingDayFieldName = "start_time";
static const QString NumOfWorkingSecondsFieldName = "num_of_working_seconds";
static const QString LunchTimeFieldName = "time_for_lunch";
static const QString LunchDurationSecondsFieldName = "lunch_duration_seconds";
static const QString IsFlexibleScheduleFieldName = "is_flexible_schedule";
}

WorkScheduleShp WorkScheduleGateway::GetById(Id id)
{
    Prepare(GetSelectByIdQuery());
    BindValue(":id", id);

    if(!Exec())
    {
        // TODO: Handle error
        return WorkScheduleShp();
    }

    if(!_query.next())
    {
        // TODO: Handle not found
        return WorkScheduleShp();
    }
    auto workSchedule = WorkScheduleShp::create(id);
    workSchedule->SetWorkdayStart(GetValueByName(StartOfWorkingDayFieldName).toTime());
    workSchedule->SetNumOfWorkingSeconds(GetValueByName(NumOfWorkingSecondsFieldName).toInt());
    workSchedule->SetLunchTime(GetValueByName(LunchTimeFieldName).toTime());
    workSchedule->SetNumOfLunchSeconds(GetValueByName(LunchDurationSecondsFieldName).toInt());
    workSchedule->SetIsFlexible(GetValueByName(IsFlexibleScheduleFieldName).toBool());

    return workSchedule;
}

QString WorkScheduleGateway::GetSelectByIdQuery()
{
    static QString query = "SELECT * FROM WorkSchedule WHERE work_schedule_id = :id;";
    return query;
}

QStringList WorkScheduleGateway::GetColumnNames() const
{
    QStringList names;
    names << WorkScheduleIdFieldName
          << StartOfWorkingDayFieldName
          << NumOfWorkingSecondsFieldName
          << LunchTimeFieldName
          << LunchDurationSecondsFieldName
          << IsFlexibleScheduleFieldName;
    return names;
}
