#include "Position.h"


Position::Position(Id id) :
    _id(id),
    _name()
{}

Id Position::GetId() const
{
    return _id;
}

QString Position::GetName() const
{
    return _name;
}

void Position::SetName(const QString& name)
{
    _name = name;
}
