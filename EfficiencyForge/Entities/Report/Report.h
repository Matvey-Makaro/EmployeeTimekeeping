#pragma once

#include <QSharedPointer>
#include <QVector>
#include <QDateTime>
#include <QDate>
#include <QTime>
#include "ReportItem.h"
#include "TypeTraits.h"
#include "Entities/User.h"

class Report;
using ReportShp = QSharedPointer<Report>;

class Report
{
public:
    static ReportShp CreateEmpty();

    Report(Id id = -1);

    Id GetId() const;

    QVector<ReportItemShp> GetItems() const;
    void SetItems(const QVector<ReportItemShp>& items);

    QDate GetDate() const;
    void SetDate(const QDate& date);

    QDateTime GetCreationTime() const;
    void SetCreationTime(const QDateTime& creationTime);

    QTime GetStartWorkingDay() const;
    void SetStartWorkingDay(const QTime& startWorkingDay);

    QTime GetEndWorkingDay() const;
    void SetEndWorkingDay(const QTime& endWorkingDay);

    UserShp GetUser() const;
    void SetUser(const UserShp& user);

private:
    Id _id;
    UserShp _user;
    QVector<ReportItemShp> _items;
    QDate _date;
    QDateTime _creationTime;
    QTime _startWorkingDay;
    QTime _endWorkingDay;
};
