#pragma once

#include <QString>
#include <QSharedPointer>

enum class UserRole
{
    Admin,
    Manager,
    Employee
};

class User
{
public:
    User() = default;

private:
    UserRole _role;
    QString _name;
    QString _surname;
    QString _patronymic;
    QString _phoneNum;
};

using UserShp = QSharedPointer<User>;
