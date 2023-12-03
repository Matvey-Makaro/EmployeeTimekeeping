#pragma once

#include <QString>
#include <QSharedPointer>
#include "TypeTraits.h"

class Department
{
public:
    // TODO: Delete later
    Department() = default;

    Department(Id id);

    Id GetId() const;

    QString GetName() const;
    void SetName(const QString& name);

private:
    Id _id;
    QString _name;
};
using DepartmentShp = QSharedPointer<Department>;
