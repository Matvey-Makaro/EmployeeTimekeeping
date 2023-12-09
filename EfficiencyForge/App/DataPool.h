#pragma once

#include <QObject>
#include <QSharedPointer>
#include <Entities/User.h>

class DataPool : public QObject
{
    Q_OBJECT
public:
    explicit DataPool(QObject *parent = nullptr);

    const UserShp& GetCurrUser() const;
    void SetCurrUser(UserShp& user);

signals:
    void CurrUserChanged(const UserShp&);

private:
    UserShp _currUser;

};
using DataPoolShp = QSharedPointer<DataPool>;
