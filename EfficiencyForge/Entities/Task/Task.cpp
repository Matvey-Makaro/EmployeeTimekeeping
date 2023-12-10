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

UserShp Task::GetReporter() const
{
    return _reporter;
}

void Task::SetReporter(const UserShp& reporterId)
{
    _reporter = reporterId;
}

UserShp Task::GetAssignee() const
{
    return _assignee;
}

void Task::SetAssignee(const UserShp& assigneeId)
{
    _assignee = assigneeId;
}

TaskTypeShp Task::GetTaskType() const
{
    return _taskType;
}

void Task::SetTaskType(const TaskTypeShp& taskTypeId)
{
    _taskType = taskTypeId;
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
