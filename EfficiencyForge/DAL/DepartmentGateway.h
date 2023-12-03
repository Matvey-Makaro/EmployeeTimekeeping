#pragma once

#include "Entities/Department.h"
#include "AbstractGateway.h"

class DepartmentGateway : public AbstractGateway
{
public:
    DepartmentGateway() = default;
    DepartmentShp GetById(Id id);

protected:
    static QString GetSelectByIdQuery();
    QStringList GetColumnNames() const override;
};

