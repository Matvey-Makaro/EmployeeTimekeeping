#pragma once

#include <QSharedPointer>
#include "Entities/User.h"
#include "IAppModel.h"

class AppModel : public IAppModel
{
public:
    AppModel();
    ~AppModel() = default;

    virtual bool IsAuthorized() const override;
    virtual UserShp GetCurrUser() const override;

public slots:
    virtual void OnTryingLogIn(const QString& login, const QString& password) override;

private:
    UserShp _currUser;
};

using AppModelShp = QSharedPointer<AppModel>;
