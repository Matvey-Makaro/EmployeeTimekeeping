#include <QDateTime>
#include "Report.h"

ReportShp Report::CreateEmpty()
{
    auto report = ReportShp::create();
    report->SetDate(QDate::currentDate());
    return report;
}

Report::Report(Id id) :
    _id(id)
{}

Id Report::GetId() const
{
    return _id;
}

QVector<ReportItemShp> Report::GetItems() const
{
    return _items;
}

void Report::SetItems(const QVector<ReportItemShp>& items)
{
    _items = items;
}

QDate Report::GetDate() const
{
    return _date;
}

void Report::SetDate(const QDate& date)
{
    _date = date;
}

QDateTime Report::GetCreationTime() const
{
    return _creationTime;
}

void Report::SetCreationTime(const QDateTime& creationTime)
{
    _creationTime = creationTime;
}

QTime Report::GetStartWorkingDay() const
{
    return _startWorkingDay;
}

void Report::SetStartWorkingDay(const QTime& startWorkingDay)
{
    _startWorkingDay = startWorkingDay;
}

QTime Report::GetEndWorkingDay() const
{
    return _endWorkingDay;
}

void Report::SetEndWorkingDay(const QTime& endWorkingDay)
{
    _endWorkingDay = endWorkingDay;
}

UserShp Report::GetUser() const
{
    return _user;
}

void Report::SetUser(const UserShp& user)
{
    _user = user;
}

void Report::SetId(const Id& id)
{
    _id = id;
}
