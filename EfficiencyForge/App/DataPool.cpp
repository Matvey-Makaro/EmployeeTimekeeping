#include "DataPool.h"

DataPool::DataPool(QObject *parent) : QObject(parent)
{

}

const UserShp& DataPool::GetCurrUser() const
{
    return _currUser;
}

// TODO: Везде сделать проверки что не устанавливается тот же самый user
void DataPool::SetCurrUser(UserShp& user)
{
    _currUser = std::move(user);
    emit CurrUserChanged(_currUser);
}

QVector<ReportItemTypeShp> DataPool::GetReportItemTypes() const
{
    return _reportItemTypes;
}

void DataPool::SetReportItemTypes(const QVector<ReportItemTypeShp>& reportItemTypes)
{
    _reportItemTypes = reportItemTypes;
    emit ReportItemTypesChanged(_reportItemTypes);
}
