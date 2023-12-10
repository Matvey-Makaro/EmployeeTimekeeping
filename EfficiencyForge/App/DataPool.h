#pragma once

#include <QObject>
#include <QSharedPointer>
#include <QVector>
#include <map>
#include "Entities/User.h"
#include "Entities/Report/Report.h"
#include "Entities/Task/Task.h"

template<typename T>
using Hash = std::map<Id, T>;

class DataPool : public QObject
{
    Q_OBJECT
public:
    explicit DataPool(QObject *parent = nullptr);

    const UserShp& GetCurrUser() const;
    void SetCurrUser(UserShp& user);

    QVector<ReportItemTypeShp> GetReportItemTypes() const;
    void SetReportItemTypes(const QVector<ReportItemTypeShp>& reportItemTypes);

    void SetTasks(const QVector<TaskShp>& tasks);
    TaskShp GetTaskById(Id taskId) const;
    QVector<TaskShp> GetTasksByReporterId(Id reporterId) const;
    QVector<TaskShp> GetTasksByAssigneeId(Id assigneeId) const;


signals:
    void CurrUserChanged(const UserShp&);
    void ReportItemTypesChanged(const  QVector<ReportItemTypeShp>&);
    void TasksChanged(const Id& userId);

private:
    UserShp _currUser;
    QVector<ReportItemTypeShp> _reportItemTypes;
    Hash<TaskShp> _tasks;
    Hash<QVector<TaskShp>> _reporterToTasks;
    Hash<QVector<TaskShp>> _assigneeToTasks;
};
using DataPoolShp = QSharedPointer<DataPool>;
