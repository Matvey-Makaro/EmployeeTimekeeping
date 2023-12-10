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

    UserShp GetReporter() const;
    void SetReporter(const UserShp& reporterId);

    UserShp GetAssignee() const;
    void SetAssignee(const UserShp& assigneeId);

    TaskTypeShp GetTaskType() const;
    void SetTaskType(const TaskTypeShp& taskTypeId);

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
    UserShp _reporter;
    UserShp _assignee;
    TaskTypeShp _taskType;
    QDateTime _creationTime;
    int _timeSpent;
    int _timeGiven;
    int _numInProject;
    QString _name;
    QString _description;
    TaskStatus _status;
};
using TaskShp = QSharedPointer<Task>;
