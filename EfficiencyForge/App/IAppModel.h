#pragma once

#include <QSharedPointer>
#include <QString>
#include "Flags.h"
#include "Entities/User.h"



class IAppModel : public QObject
{
public:
    virtual ~IAppModel() = default;

    virtual bool IsAuthorized() const = 0;
    virtual UserShp GetCurrUser() const = 0;

public slots:
    virtual void OnTryingLogIn(const QString& login, const QString& password) = 0;

signals:
    void LogInFinished(AuthorizationResCode);
};

using IAppModelShp =QSharedPointer<IAppModel>;
