#pragma once

#include <QSharedPointer>
#include <QString>
#include "TypeTraits.h"

class TaskType
{
public:
    TaskType(Id id);

    Id GetId() const;

    QString GetName() const;
    void SetName(const QString& name);

private:
    Id _id;
    QString _name;
};
using TaskTypeShp = QSharedPointer<TaskType>;
