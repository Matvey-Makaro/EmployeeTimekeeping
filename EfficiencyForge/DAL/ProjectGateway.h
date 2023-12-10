#pragma once

#include <QSharedPointer>
#include "Entities/Project.h"
#include "Utils/Loggers/ILogger.h"
#include "AbstractGateway.h"

class ProjectGateway : public AbstractGateway
{
public:
    ProjectGateway() = default;

    QVector<ProjectShp> GetAll(ILogger* l = nullptr);
    ProjectShp GetById(Id id, ILogger* l = nullptr);

protected:
    static QString GetSelectByIdQuery();
    static QString GetSelectAllQuery();
    QStringList GetColumnNames() const override;
    ProjectShp ExtractProject(ILogger* l = nullptr);
};
using ProjectGatewayShp = QSharedPointer<ProjectGateway>;
