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

void DataPool::SetTasks(const QVector<TaskShp>& tasks)
{
    for(const auto& t : tasks)
    {
        _tasks[t->GetId()] = t;
        _reporterToTasks[t->GetReporter()->GetId()].push_back(t);
        _assigneeToTasks[t->GetAssignee()->GetId()].push_back(t);
    }
}

TaskShp DataPool::GetTaskById(Id taskId) const
{
    auto it = _tasks.find(taskId);
    if(it == _tasks.cend())
        return {};
    return it->second;
}

QVector<TaskShp> DataPool::GetTasksByReporterId(Id reporterId) const
{
    auto it = _reporterToTasks.find(reporterId);
    if(it == _reporterToTasks.cend())
        return {};
    return it->second;
}

QVector<TaskShp> DataPool::GetTasksByAssigneeId(Id assigneeId) const
{
    auto it = _assigneeToTasks.find(assigneeId);
    if(it == _assigneeToTasks.cend())
        return {};
    return it->second;
}
