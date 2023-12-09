#pragma once

#include <QVector>
#include <QSharedPointer>
#include "Entities/User.h"

struct FindUsersContext
{
    QVector<UserShp> users;
};
using FindUsersContextShp = QSharedPointer<FindUsersContext>;

