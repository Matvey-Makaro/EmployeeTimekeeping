#include "User.h"

User::User(Id id) :
    _id(id),
    _name(),
    _surname(),
    _patronymic(),
    _phoneNum(),
    _role(UserRole::Employee),
    _position(),
    _department(),
    _workSchedule()
{}

Id User::GetId() const
{
    return _id;
}

QString User::GetName() const
{
    return _name;
}

void User::SetName(const QString& name)
{
    _name = name;
}

QString User::GetSurname() const
{
    return _surname;
}

void User::SetSurname(const QString& surname)
{
    _surname = surname;
}

QString User::GetPatronymic() const
{
    return _patronymic;
}

void User::SetPatronymic(const QString& patronymic)
{
    _patronymic = patronymic;
}

QString User::GetPhoneNum() const
{
    return _phoneNum;
}

void User::SetPhoneNum(const QString& phoneNum)
{
    _phoneNum = phoneNum;
}

UserRole User::GetRole() const
{
    return _role;
}

void User::SetRole(const UserRole& role)
{
    _role = role;
}

PositionShp User::GetPosition() const
{
    return _position;
}

void User::SetPosition(const PositionShp& position)
{
    _position = position;
}

DepartmentShp User::GetDepartment() const
{
    return _department;
}

void User::SetDepartment(const DepartmentShp& department)
{
    _department = department;
}

WorkScheduleShp User::GetWorkSchedule() const
{
    return _workSchedule;
}

void User::SetWorkSchedule(const WorkScheduleShp& workSchedule)
{
    _workSchedule = workSchedule;
}
