#pragma once

#include <QSharedPointer>
#include <QString>
#include <QSqlQuery>
#include "Entities/User.h"
#include "AbstractGateway.h"
#include "Utils/Loggers/ILogger.h"

class UserGateway : public AbstractGateway
{
public:
    UserGateway() = default;
    UserShp GetUserByLoginPassword(const QString& login,
                                   const QString& password,
                                   ILogger* l = nullptr);
    UserShp GetById(Id id, ILogger* l = nullptr);
    QVector<UserShp> GetAll(ILogger* l = nullptr);

protected:
    static QString GetSelectByLoginPasswordQuery();
    static QString GetSelectByIdQuery();
    static QString GetSelectAllQuery();

    UserShp CreateUser(ILogger* l = nullptr);
    PositionShp LoadPosition(Id positionId) const;
    DepartmentShp LoadDepartment(Id departmentId) const;
    WorkScheduleShp LoadWorkSchedule(Id workScheduleId) const;

    QStringList GetColumnNames() const override;
    UserRole Map(const QString roleStr) const;
};
using UserGatewayShp = QSharedPointer<UserGateway>;
