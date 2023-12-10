#pragma once

#include <QSharedPointer>
#include "Entities/Task/Task.h"
#include "Entities/Project.h"
#include "Utils/Loggers/ILogger.h"
#include "AbstractGateway.h"

class TaskGateway : public AbstractGateway
{
public:
    TaskGateway() = default;

    QVector<TaskShp> GetAll(ILogger* l = nullptr);
    TaskShp GetById(Id id, ILogger* l = nullptr);

protected:
    static QString GetSelectByIdQuery();
    static QString GetSelectAllQuery();
    QStringList GetColumnNames() const override;
    TaskShp ExtractTask(ILogger* l = nullptr);
    ProjectShp GetProject(Id id, ILogger* l = nullptr);
    UserShp GetUser(Id id, ILogger* l = nullptr);
    TaskStatus ToTaskStatus(const QString& str);
};
using TaskGatewayShp = QSharedPointer<TaskGateway>;
