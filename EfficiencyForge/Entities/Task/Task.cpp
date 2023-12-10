#include "Task.h"

Task::Task(Id id) :
    _id(id)
{}

ProjectShp Task::GetProject() const
{
    return _project;
}

void Task::SetProject(const ProjectShp& project)
{
    _project = project;
}

UserShp Task::GetReporterId() const
{
    return _reporterId;
}

void Task::SetReporterId(const UserShp& reporterId)
{
    _reporterId = reporterId;
}

UserShp Task::GetAssigneeId() const
{
    return _assigneeId;
}

void Task::SetAssigneeId(const UserShp& assigneeId)
{
    _assigneeId = assigneeId;
}

TaskTypeShp Task::GetTaskTypeId() const
{
    return _taskTypeId;
}

void Task::SetTaskTypeId(const TaskTypeShp& taskTypeId)
{
    _taskTypeId = taskTypeId;
}

QDateTime Task::GetCreationTime() const
{
    return _creationTime;
}

void Task::SetCreationTime(const QDateTime& creationTime)
{
    _creationTime = creationTime;
}

int Task::GetTimeSpent() const
{
    return _timeSpent;
}

void Task::SetTimeSpent(int timeSpent)
{
    _timeSpent = timeSpent;
}

int Task::GetTimeGiven() const
{
    return _timeGiven;
}

void Task::SetTimeGiven(int timeGiven)
{
    _timeGiven = timeGiven;
}

int Task::GetNumInProject() const
{
    return _numInProject;
}

void Task::SetNumInProject(int numInProject)
{
    _numInProject = numInProject;
}

QString Task::GetName() const
{
    return _name;
}

void Task::SetName(const QString& name)
{
    _name = name;
}

QString Task::GetDescription() const
{
    return _description;
}

void Task::SetDescription(const QString& description)
{
    _description = description;
}

TaskStatus Task::GetStatus() const
{
    return _status;
}

void Task::SetStatus(const TaskStatus& status)
{
    _status = status;
}

Id Task::GetId() const
{
    return _id;
}
