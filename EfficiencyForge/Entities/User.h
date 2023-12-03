#pragma once

#include <QString>
#include <QSharedPointer>
#include "TypeTraits.h"
#include "Position.h"
#include "Department.h"
#include "WorkSchedule.h"

enum class UserRole
{
    Admin,
    Manager,
    Employee,
    Unknown,
};

// TODO: Change return QString -> const QString&, where possible set by value
class User
{
public:
    User(Id id);

    Id GetId() const;

    QString GetName() const;
    void SetName(const QString& name);

    QString GetSurname() const;
    void SetSurname(const QString& surname);

    QString GetPatronymic() const;
    void SetPatronymic(const QString& patronymic);

    QString GetPhoneNum() const;
    void SetPhoneNum(const QString& phoneNum);

    UserRole GetRole() const;
    void SetRole(const UserRole& role);

    PositionShp GetPosition() const;
    void SetPosition(const PositionShp& position);

    DepartmentShp GetDepartment() const;
    void SetDepartment(const DepartmentShp& department);

    WorkScheduleShp GetWorkSchedule() const;
    void SetWorkSchedule(const WorkScheduleShp& workSchedule);

private:
    Id _id;
    QString _name;
    QString _surname;
    QString _patronymic;
    QString _phoneNum;
    UserRole _role;
    PositionShp _position;
    DepartmentShp _department;
    WorkScheduleShp _workSchedule;
};

using UserShp = QSharedPointer<User>;
