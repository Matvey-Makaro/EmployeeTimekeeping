#pragma once

#include <QObject>
#include <QSharedPointer>
#include <QVector>
#include <Entities/User.h>
#include "Entities/Report/Report.h"

class DataPool : public QObject
{
    Q_OBJECT
public:
    explicit DataPool(QObject *parent = nullptr);

    const UserShp& GetCurrUser() const;
    void SetCurrUser(UserShp& user);

    QVector<ReportItemTypeShp> GetReportItemTypes() const;
    void SetReportItemTypes(const QVector<ReportItemTypeShp>& reportItemTypes);

signals:
    void CurrUserChanged(const UserShp&);

private:
    UserShp _currUser;
    QVector<ReportItemTypeShp> _reportItemTypes;
};
using DataPoolShp = QSharedPointer<DataPool>;
