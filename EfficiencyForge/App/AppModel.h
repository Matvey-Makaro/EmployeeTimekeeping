#pragma once

#include <QObject>
#include <QSharedPointer>
#include "Entities/User.h"

class AppModel : public QObject
{
    Q_OBJECT
public:
    AppModel(QObject* parent = nullptr);
    ~AppModel() = default;

    bool IsAuthorized() const;
    UserShp GetCurrUser() const;

public slots:
    void OnTryingLogIn(const QString& login, const QString& password);

private:
    UserShp _currUser;
};

using AppModelShp = QSharedPointer<AppModel>;
