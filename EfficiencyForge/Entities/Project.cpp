#include "Project.h"


Project::Project(Id id) :
    _id(id)
{

}

Id Project::GetId() const
{
    return _id;
}

UserShp Project::GetManager() const
{
    return _manager;
}

void Project::SetManager(const UserShp& manager)
{
    _manager = manager;
}

QString Project::GetName() const
{
    return _name;
}

void Project::SetName(const QString& name)
{
    _name = name;
}
