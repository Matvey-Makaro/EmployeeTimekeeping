#include <QVariant>
#include <QSqlRecord>
#include "PositionGateway.h"

namespace
{
static const QString PositionsIdFieldName = QStringLiteral("positions_id");
static const QString NameFieldName = QStringLiteral("name");
}

PositionShp PositionGateway::GetById(Id id)
{
    Prepare(GetSelectByIdQuery());
    BindValue(":id", id);

    if(!Exec())
    {
        // TODO: Handle error
        return PositionShp();
    }

    if(!_query.next())
    {
        // TODO: Handle not found
        return PositionShp();
    }
    auto pos = PositionShp::create(id);
    pos->SetName(GetValueByName(NameFieldName).toString());
    return pos;
}

QString PositionGateway::GetSelectByIdQuery()
{
    static QString query = QStringLiteral("SELECT * FROM Positions WHERE positions_id = :id;");
    return query;
}

QStringList PositionGateway::GetColumnNames() const
{
    QStringList names;
    names << PositionsIdFieldName
          << NameFieldName;
    return names;
}
