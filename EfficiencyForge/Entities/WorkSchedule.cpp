#include "WorkSchedule.h"

WorkSchedule::WorkSchedule(Id id) :
    _id(id),
    _workdayStart(),
    _numOfWorkingSeconds(0),
    _lunchTime(),
    _numOfLunchSeconds(0)
{}

Id WorkSchedule::GetId() const
{
    return _id;
}

const QTime& WorkSchedule::GetWorkdayStart() const
{
    return _workdayStart;
}

void WorkSchedule::SetWorkdayStart(const QTime& workdayStart)
{
    _workdayStart = workdayStart;
}

int WorkSchedule::GetNumOfWorkingSeconds() const
{
    return _numOfWorkingSeconds;
}

void WorkSchedule::SetNumOfWorkingSeconds(int numOfWorkingSeconds)
{
    _numOfWorkingSeconds = numOfWorkingSeconds;
}

const QTime& WorkSchedule::GetLunchTime() const
{
    return _lunchTime;
}

void WorkSchedule::SetLunchTime(const QTime& lunchTime)
{
    _lunchTime = lunchTime;
}

int WorkSchedule::GetNumOfLunchSeconds() const
{
    return _numOfLunchSeconds;
}

void WorkSchedule::SetNumOfLunchSeconds(int numOfLunchSeconds)
{
    _numOfLunchSeconds = numOfLunchSeconds;
}

bool WorkSchedule::IsFlexible() const
{
    return _isFlexible;
}

void WorkSchedule::SetIsFlexible(bool isFlexible)
{
    _isFlexible = isFlexible;
}
