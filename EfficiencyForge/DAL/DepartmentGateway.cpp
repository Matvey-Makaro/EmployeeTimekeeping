#include <QDebug>
#include <QVariant>
#include <QSqlRecord>
#include "DepartmentGateway.h"

namespace
{
static const QString DepartmentIdFieldName = QStringLiteral("department_id");
static const QString NameFieldName = QStringLiteral("name");
}

DepartmentShp DepartmentGateway::GetById(Id id)
{
    Prepare(GetSelectByIdQuery());
    BindValue(":id", id);

    if(!Exec())
    {
        // TODO: Handle error
        return DepartmentShp();
    }

    qDebug() << "DepartmentGateway::GetById()" << "Last query:" << _query.lastQuery();

    if(!_query.next())
    {
        // TODO: Handle not found
        return DepartmentShp();
    }
    auto department = DepartmentShp::create(id);
    department->SetName(GetValueByName(NameFieldName).toString());
    return department;
}

QString DepartmentGateway::GetSelectByIdQuery()
{
    static const QString query = QStringLiteral("SELECT * FROM Department WHERE department_id = :id;");
    return query;
}

QStringList DepartmentGateway::GetColumnNames() const
{
    QStringList names;
    names << DepartmentIdFieldName
          << NameFieldName;
    return names;
}
