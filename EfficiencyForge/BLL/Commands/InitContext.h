#pragma once

#include <QSharedPointer>
#include <QVector>
#include "Entities/Report/ReportItemType.h"
#include "Entities/Task/Task.h"

struct InitContext
{
    QVector<ReportItemTypeShp> reportItemTypes;
    QVector<TaskShp> tasks;
};
using InitContextShp = QSharedPointer<InitContext>;
