#pragma once

#include <QString>
#include <QSharedPointer>
#include "TypeTraits.h"

class Position
{
public:
    // TODO: delete
    Position() = default;

    Position(Id id);

    Id GetId() const;

    QString GetName() const;
    void SetName(const QString& name);

private:
    Id _id;
    QString _name;
};
using PositionShp = QSharedPointer<Position>;
