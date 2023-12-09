#include <QDebug>
#include <QVariant>
#include <QSqlError>
#include "DAL/DB.h"
#include "PositionGateway.h"
#include "DepartmentGateway.h"
#include "WorkScheduleGateway.h"
#include "UserGateway.h"
#include "Flags.h"

namespace
{
static const QString UserIdFieldName = "user_id";
static const QString NameFieldName = "name";
static const QString SurnameFieldName = "surname";
static const QString PatronymicFieldName = "patronymic";
static const QString PhoneNumFieldName = "phone_num";
static const QString RoleFieldName = "role";
static const QString LoginFieldName = "login";
static const QString PasswordFieldName = "password";
static const QString PositionsIdFieldName = "positions_id";
static const QString DepartmentIdFieldName = "department_id";
static const QString WorkScheduleIdFieldName = "work_schedule_id";
}


UserShp UserGateway::SelectUserByLoginPassword(const QString& login,
                                               const QString& password,
                                               ILogger* l)
{
    Prepare(GetSelectByLoginPasswordQuery());
    BindValue(":login", login);
    BindValue(":password", password);

    if(!Exec())
    {
        if(l)
            l->WriteCritical(FromFlags::UserGateway, CodeFlags::ExecError, _query.lastError().databaseText());
        return UserShp();
    }

    qDebug() << "UserGateway::SelectUserByLoginPassword" << "Last query:" << _query.lastQuery();

    if(!_query.next())
    {
        if(l)
            l->WriteWarning(FromFlags::UserGateway, CodeFlags::NotFound, "User not found");
        return UserShp();
    }
    Q_ASSERT_X(_query.size() == 1,
               "UserGateway::SelectUserByLoginPassword()",
               "There should be no users with the same login and password");

    return CreateUser();
}

QString UserGateway::GetSelectByLoginPasswordQuery()
{
    static const QString query = QStringLiteral("SELECT * FROM User WHERE login = :login AND password = :password;");
    return query;
}

UserShp UserGateway::CreateUser()
{
    Id id = GetValueByName(UserIdFieldName).toLongLong();
    auto user = UserShp::create(id);
    user->SetName(GetValueByName(NameFieldName).toString());
    user->SetSurname(GetValueByName(SurnameFieldName).toString());
    user->SetPatronymic(GetValueByName(PatronymicFieldName).toString());
    user->SetPhoneNum(GetValueByName(PhoneNumFieldName).toString());
    auto role = Map(GetValueByName(RoleFieldName).toString());
    user->SetRole(role);

    Id positionId = GetValueByName(PositionsIdFieldName).toLongLong();
    user->SetPosition(LoadPosition(positionId));

    Id departmentId = GetValueByName(DepartmentIdFieldName).toLongLong();
    user->SetDepartment(LoadDepartment(departmentId));

    Id workScheduleId = GetValueByName(WorkScheduleIdFieldName).toLongLong();
    user->SetWorkSchedule(LoadWorkSchedule(workScheduleId));
    return user;
}

PositionShp UserGateway::LoadPosition(Id positionId) const
{
    PositionGateway positionGateway;
    return positionGateway.GetById(positionId);
}

DepartmentShp UserGateway::LoadDepartment(Id departmentId) const
{
    DepartmentGateway departmentGateway;
    return departmentGateway.GetById(departmentId);
}

WorkScheduleShp UserGateway::LoadWorkSchedule(Id workScheduleId) const
{
    WorkScheduleGateway workScheduleGateway;
    return workScheduleGateway.GetById(workScheduleId);
}


QStringList UserGateway::GetColumnNames() const
{
    QStringList names;
    names << UserIdFieldName
          << NameFieldName
          << SurnameFieldName
          << PatronymicFieldName
          << PhoneNumFieldName
          << RoleFieldName
          << LoginFieldName
          << PasswordFieldName
          << PositionsIdFieldName
          << DepartmentIdFieldName
          << WorkScheduleIdFieldName;
    return names;
}

UserRole UserGateway::Map(const QString roleStr) const
{
    if(roleStr == "Admin")
        return UserRole::Admin;
    if(roleStr == "Manager")
        return UserRole::Manager;
    if(roleStr == "Employee")
        return UserRole::Employee;
    return UserRole::Unknown;
}
