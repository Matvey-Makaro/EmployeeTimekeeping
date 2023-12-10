#pragma once

#include <QSharedPointer>
#include <QString>
#include "TypeTraits.h"

class ReportItemType
{
public:
    ReportItemType(Id id);

    Id GetId() const;

    QString GetName() const;
    void SetName(const QString& name);

    bool IsWorkingTime() const;
    void SetIsWorkingTime(bool isWorkingTime);

private:
    Id _id;
    QString _name;
    bool _isWorkingTime;
};
using ReportItemTypeShp = QSharedPointer<ReportItemType>;
