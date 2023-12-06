#pragma once

#include <QObject>
#include <QSharedPointer>
#include "Operations/IOperation.h"

class IOperationModel : public QObject
{
    Q_OBJECT
public:
    using QObject::QObject;
    virtual ~IOperationModel() = default;

    virtual bool DoOperation(const IOperationShp&) = 0;
    virtual void DismissOperation(const IOperationShp&) = 0;

signals:
    void Finished(const IOperationShp&);
    void Failed(const IOperationShp&);
    void Dismissed(const IOperationShp&);
};
using IOperationModelShp = QSharedPointer<IOperationModel>;
