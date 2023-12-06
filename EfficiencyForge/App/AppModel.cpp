#include <QDebug>
#include "AppModel.h"

AppModel::AppModel(QObject* parent) :
    QObject(parent)
{}

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
    qDebug() << "AppModel::OnTryingLogIn()" << "login:" << login << "password:" << password;
    // TODO: Check correctness of login and password



}

