#include <QSqlError>
#include "ProjectGateway.h"
#include "UserGateway.h"
#include "TaskGateway.h"

namespace
{
static const QString IdFieldName = QStringLiteral("task_id");
static const QString ProjectIdFieldName = QStringLiteral("project_id");
static const QString ReporterIdFieldName = QStringLiteral("reporter_id");
static const QString AssigneeIdFieldName = QStringLiteral("assignee_id");
static const QString TaskTypeIdFieldName = QStringLiteral("task_type_id");
static const QString CreationDateFieldName = QStringLiteral("creation_data");
static const QString TimeSpentFieldName = QStringLiteral("time_spent");
static const QString TimeGivenFieldName = QStringLiteral("time_given");
static const QString NumInProjectFieldName = QStringLiteral("num_in_project");
static const QString NameFieldName = QStringLiteral("name");
static const QString DescriptionFieldName = QStringLiteral("description");
static const QString StatusFieldName = QStringLiteral("status");
}

QVector<TaskShp> TaskGateway::GetAll(ILogger* l)
{
    Prepare(GetSelectAllQuery());
    if(!Exec())
    {
        if(l)
            l->WriteCritical(FromFlags::TaskGateway, CodeFlags::ExecError, _query.lastError().databaseText());
        return {};
    }

    QVector<TaskShp> result;
    result.reserve(_query.size());
    while(_query.next())
    {
       result.push_back(ExtractTask(l));
    }
    return result;
}

TaskShp TaskGateway::GetById(Id id, ILogger* l)
{
    Prepare(GetSelectByIdQuery());
    BindValue(":id", id);

    if(!Exec())
    {
        if(l)
            l->WriteCritical(FromFlags::TaskGateway, CodeFlags::ExecError, _query.lastError().databaseText());
        return {};
    }

    if(!_query.next())
    {
        if(l)
            l->WriteWarning(FromFlags::TaskGateway, CodeFlags::NotFound, "TaskGateway not found");
        return {};
    }
    return ExtractTask(l);
}

QString TaskGateway::GetSelectByIdQuery()
{
    return QStringLiteral("SELECT * FROM Task WHERE task_id = 1;");
}

QString TaskGateway::GetSelectAllQuery()
{
    return QStringLiteral("SELECT * FROM Task");
}

QStringList TaskGateway::GetColumnNames() const
{
    QStringList names;
    names << IdFieldName
          << ProjectIdFieldName
          << ReporterIdFieldName
          << AssigneeIdFieldName
          << TaskTypeIdFieldName
          << CreationDateFieldName
          << TimeSpentFieldName
          << TimeGivenFieldName
          << NumInProjectFieldName
          << NameFieldName
          << DescriptionFieldName
          << StatusFieldName;
    return names;
}

TaskShp TaskGateway::ExtractTask(ILogger* l)
{
    Id id = GetValueByName(IdFieldName).toLongLong();
    auto task = TaskShp::create(id);

    Id taskId = GetValueByName(ProjectIdFieldName).toLongLong();
    task->SetProject(GetProject(taskId, l));

    Id reporterId = GetValueByName(ReporterIdFieldName).toLongLong();
    task->SetReporter(GetUser(reporterId, l));

    Id assigneeId = GetValueByName(AssigneeIdFieldName).toLongLong();
    task->SetAssignee(GetUser(assigneeId, l));

    task->SetCreationTime(GetValueByName(CreationDateFieldName).toDateTime());
    task->SetTimeSpent(GetValueByName(TimeSpentFieldName).toInt());
    task->SetTimeGiven(GetValueByName(TimeGivenFieldName).toInt());
    task->SetNumInProject(GetValueByName(NumInProjectFieldName).toInt());
    task->SetName(GetValueByName(NameFieldName).toString());
    task->SetDescription(GetValueByName(DescriptionFieldName).toString());

    QString status = GetValueByName(StatusFieldName).toString();
    task->SetStatus(ToTaskStatus(status));
    return task;
}

ProjectShp TaskGateway::GetProject(Id id, ILogger* l)
{
    ProjectGateway gateway;
    return gateway.GetById(id, l);
}

UserShp TaskGateway::GetUser(Id id, ILogger* l)
{
    UserGateway gateway;
    return gateway.GetById(id, l);
}

TaskStatus TaskGateway::ToTaskStatus(const QString& str)
{
    if(str == "Open")
        return TaskStatus::Open;
    if(str == "Close")
        return TaskStatus::Close;
    if(str == "InProgress")
        return TaskStatus::InProgress;
    if(str == "InReview")
        return TaskStatus::InReview;
    if(str == "Backlog")
        return TaskStatus::Backlog;
    Q_ASSERT(false);
    return TaskStatus::Open;
}
