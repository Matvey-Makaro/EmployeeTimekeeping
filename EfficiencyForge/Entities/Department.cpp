#include "Department.h"

Department::Department(Id id) :
    _id(id),
    _name()
{}

Id Department::GetId() const
{
    return _id;
}

QString Department::GetName() const
{
    return _name;
}

void Department::SetName(const QString& name)
{
    _name = name;
}
