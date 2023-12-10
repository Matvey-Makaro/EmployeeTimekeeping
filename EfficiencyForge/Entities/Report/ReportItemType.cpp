#include "ReportItemType.h"

ReportItemType::ReportItemType(Id id) :
    _id(id)
{

}

Id ReportItemType::GetId() const
{
    return _id;
}

QString ReportItemType::GetName() const
{
    return _name;
}

void ReportItemType::SetName(const QString& name)
{
    _name = name;
}

bool ReportItemType::IsWorkingTime() const
{
    return _isWorkingTime;
}

void ReportItemType::SetIsWorkingTime(bool isWorkingTime)
{
    _isWorkingTime = isWorkingTime;
}
