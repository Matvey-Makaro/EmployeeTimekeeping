#pragma once

#include <QSharedPointer>
#include <QTime>
#include <QString>
#include "TypeTraits.h"
#include "ReportItemType.h"

class Task;
using TaskShp = QSharedPointer<Task>;

class ReportItem
{
public:
    ReportItem(Id id = -1);

    Id GetId() const;

    TaskShp GetTask() const;
    void SetTask(const TaskShp& task);

    ReportItemTypeShp GetType() const;
    void SetType(const ReportItemTypeShp& type);

    QTime GetStart() const;
    void SetStart(const QTime& start);

    QTime GetEnd() const;
    void SetEnd(const QTime& end);

    QString GetText() const;
    void SetText(const QString& text);

private:
    Id _id;
    TaskShp _task;
    ReportItemTypeShp _type;
    QTime _start;
    QTime _end;
    QString _text;
};
using ReportItemShp = QSharedPointer<ReportItem>;
