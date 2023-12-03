#pragma once

#include <QSharedPointer>
#include <QTime>
#include "TypeTraits.h"

class WorkSchedule
{
public:
    WorkSchedule(Id id);

    Id GetId() const;

    const QTime& GetWorkdayStart() const;
    void SetWorkdayStart(const QTime& workdayStart);

    int GetNumOfWorkingSeconds() const;
    void SetNumOfWorkingSeconds(int numOfWorkingSeconds);

    const QTime& GetLunchTime() const;
    void SetLunchTime(const QTime& lunchTime);

    int GetNumOfLunchSeconds() const;
    void SetNumOfLunchSeconds(int numOfLunchSeconds);

    bool IsFlexible() const;
    void SetIsFlexible(bool isFlexible);

private:
    Id _id;
    QTime _workdayStart;
    int _numOfWorkingSeconds;
    QTime _lunchTime;
    int _numOfLunchSeconds;
    bool _isFlexible;
};

using WorkScheduleShp = QSharedPointer<WorkSchedule>;
