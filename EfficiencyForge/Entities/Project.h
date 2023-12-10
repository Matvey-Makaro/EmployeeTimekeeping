#pragma once

#include <QSharedPointer>
#include <QString>
#include "TypeTraits.h"
#include "Entities/User.h"

class Project
{
public:
    Project(Id id);

    Id GetId() const;

    UserShp GetManager() const;
    void SetManager(const UserShp& manager);

    QString GetName() const;
    void SetName(const QString& name);

private:
    Id _id;
    UserShp _manager;
    QString _name;
};
using ProjectShp = QSharedPointer<Project>;
