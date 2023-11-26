#include "AppModel.h"

AppModel::AppModel()
{

}

bool AppModel::IsAuthorized() const
{
    return !_currUser.isNull();
}

UserShp AppModel::GetCurrUser() const
{
    return _currUser;
}

void AppModel::OnTryingLogIn(const QString &login, const QString &password)
{
    // TODO: Check correctness of login and password

}

