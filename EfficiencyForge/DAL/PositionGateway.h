#pragma once

#include "Entities/Position.h"
#include "AbstractGateway.h"

class PositionGateway : public AbstractGateway
{
public:
    PositionGateway() = default;

    PositionShp GetById(Id id);

protected:
    static QString GetSelectByIdQuery();
    QStringList GetColumnNames() const override;
};

