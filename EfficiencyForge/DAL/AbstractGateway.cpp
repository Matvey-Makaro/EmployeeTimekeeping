#include <QSqlRecord>
#include "DB.h"
#include "AbstractGateway.h"

AbstractGateway::AbstractGateway() :
    _query(DB::GetQSqlDatabase()),
    _nameToIndex()
{}

bool AbstractGateway::Prepare(const QString& query)
{
    return _query.prepare(query);
}

void AbstractGateway::BindValue(const QString& placeholder, const QVariant& val, QSql::ParamType paramType)
{
    _query.bindValue(placeholder, val, paramType);
}

bool AbstractGateway::Exec()
{
    bool res = _query.exec();
    UpdateNameToIndex();
    return res;
}

void AbstractGateway::UpdateNameToIndex()
{
    auto record = _query.record();
    _nameToIndex.clear();
    const auto names = GetColumnNames();
    for(const auto& name : names)
        _nameToIndex[name] = record.indexOf(name);
}

QVariant AbstractGateway::GetValueByName(const QString& name) const
{
    auto findIt = _nameToIndex.find(name);
    if(findIt != _nameToIndex.cend())
        return _query.value(findIt->second);
    return QVariant();
}
