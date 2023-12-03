#pragma once

#include <QStringList>
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <unordered_map>

class AbstractGateway
{
public:
    AbstractGateway();
    virtual ~AbstractGateway() = default;

protected:
    using NameToIndex = std::unordered_map<QString, int>;

    virtual bool Prepare(const QString& query);
    virtual void BindValue(const QString& placeholder, const QVariant& val, QSql::ParamType paramType = QSql::In);
    virtual bool Exec();

    virtual void UpdateNameToIndex();
    virtual QStringList GetColumnNames() const = 0;

    virtual QVariant GetValueByName(const QString& name) const;

protected:
    QSqlQuery _query;
    NameToIndex _nameToIndex;
};

