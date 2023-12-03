#pragma once

#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSharedPointer>
#include "TypeTraits.h"
#include "Entities/WorkSchedule.h"
#include "AbstractGateway.h"

class WorkScheduleGateway : public AbstractGateway
{
public:
    WorkScheduleGateway() = default;
    WorkScheduleShp GetById(Id id);

protected:
    static QString GetSelectByIdQuery();
    QStringList GetColumnNames() const override;
};

