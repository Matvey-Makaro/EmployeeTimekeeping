#pragma once

#include <QString>
#include "QSqlQuery"
#include "Entities/User.h"
#include "AbstractGateway.h"

class UserGateway : public AbstractGateway
{
public:
    UserGateway() = default;
    UserShp SelectUserByLoginPassword(const QString& login, const QString& password);

protected:
    static QString GetSelectByLoginPasswordQuery();

    UserShp CreateUser();
    PositionShp LoadPosition(Id positionId) const;
    DepartmentShp LoadDepartment(Id departmentId) const;
    WorkScheduleShp LoadWorkSchedule(Id workScheduleId) const;

    QStringList GetColumnNames() const override;
    UserRole Map(const QString roleStr) const;
};

