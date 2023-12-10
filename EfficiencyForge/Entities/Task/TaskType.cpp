#include "TaskType.h"

TaskType::TaskType(Id id) :
    _id(id)
{

}

Id TaskType::GetId() const
{
    return _id;
}

QString TaskType::GetName() const
{
    return _name;
}

void TaskType::SetName(const QString& name)
{
    _name = name;
}
