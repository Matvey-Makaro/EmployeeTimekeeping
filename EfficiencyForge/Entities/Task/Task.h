#pragma once

#include <QSharedPointer>
#include <QDateTime>
#include "TypeTraits.h"
#include "TaskType.h"
#include "Entities/User.h"

class Project;
using ProjectShp = QSharedPointer<Project>;

enum class TaskStatus
{
    Open,
    Close,
    InProgress,
    InReview,
    Backlog,
};

class Task
{
public:
    Task(Id id);

    Id GetId() const;

    ProjectShp GetProject() const;
    void SetProject(const ProjectShp& project);

    UserShp GetReporterId() const;
    void SetReporterId(const UserShp& reporterId);

    UserShp GetAssigneeId() const;
    void SetAssigneeId(const UserShp& assigneeId);

    TaskTypeShp GetTaskTypeId() const;
    void SetTaskTypeId(const TaskTypeShp& taskTypeId);

    QDateTime GetCreationTime() const;
    void SetCreationTime(const QDateTime& creationTime);

    int GetTimeSpent() const;
    void SetTimeSpent(int timeSpent);

    int GetTimeGiven() const;
    void SetTimeGiven(int timeGiven);

    int GetNumInProject() const;
    void SetNumInProject(int numInProject);

    QString GetName() const;
    void SetName(const QString& name);

    QString GetDescription() const;
    void SetDescription(const QString& description);

    TaskStatus GetStatus() const;
    void SetStatus(const TaskStatus& status);

private:
    Id _id;
    ProjectShp _project;
    UserShp _reporterId;
    UserShp _assigneeId;
    TaskTypeShp _taskTypeId;
    QDateTime _creationTime;
    int _timeSpent;
    int _timeGiven;
    int _numInProject;
    QString _name;
    QString _description;
    TaskStatus _status;
};
using TaskShp = QSharedPointer<Task>;
