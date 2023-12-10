#include <QSqlError>
#include "UserGateway.h"
#include "ProjectGateway.h"

namespace
{
static const QString IdFieldName = QStringLiteral("project_id");
static const QString NameFieldName = QStringLiteral("name");
static const QString ManagerIdFieldName = QStringLiteral("manager_id");
}

QVector<ProjectShp> ProjectGateway::GetAll(ILogger* l)
{
    Prepare(GetSelectAllQuery());
    if(!Exec())
    {
        if(l)
            l->WriteCritical(FromFlags::ProjectGateway, CodeFlags::ExecError, _query.lastError().databaseText());
        return {};
    }

    QVector<ProjectShp> result;
    result.reserve(_query.size());
    while(_query.next())
    {
       result.push_back(ExtractProject(l));
    }
    return result;
}

ProjectShp ProjectGateway::GetById(Id id, ILogger* l)
{
    Prepare(GetSelectByIdQuery());
    BindValue(":id", id);

    if(!Exec())
    {
        if(l)
            l->WriteCritical(FromFlags::ProjectGateway, CodeFlags::ExecError, _query.lastError().databaseText());
        return {};
    }

    if(!_query.next())
    {
        if(l)
            l->WriteWarning(FromFlags::ProjectGateway, CodeFlags::NotFound, "ProjectGateway not found");
        return {};
    }
    return ExtractProject(l);
}

QString ProjectGateway::GetSelectByIdQuery()
{
    return QStringLiteral("SELECT * FROM Project WHERE project_id = 1;");
}

QString ProjectGateway::GetSelectAllQuery()
{
    return QStringLiteral("SELECT * FROM Project;");
}

QStringList ProjectGateway::GetColumnNames() const
{
    QStringList names;
    names << IdFieldName
          << NameFieldName
          << ManagerIdFieldName;
    return names;
}

ProjectShp ProjectGateway::ExtractProject(ILogger* l)
{
    Id id = GetValueByName(IdFieldName).toLongLong();
    auto project = ProjectShp::create(id);
    project->SetName(GetValueByName(NameFieldName).toString());

    Id managetId = GetValueByName(ManagerIdFieldName).toLongLong();
    UserGateway userGateway;
    auto user = userGateway.GetById(managetId, l);
    project->SetManager(std::move(user));
    return project;
}
