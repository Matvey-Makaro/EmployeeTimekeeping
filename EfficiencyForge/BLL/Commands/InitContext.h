#pragma once

#include <QSharedPointer>
#include <QVector>
#include "Entities/Report/ReportItemType.h"

struct InitContext
{
    QVector<ReportItemTypeShp> _reportItemTypes;
};
using InitContextShp = QSharedPointer<InitContext>;
