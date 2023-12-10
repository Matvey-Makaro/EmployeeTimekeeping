#include "ReportItem.h"

ReportItem::ReportItem(Id id) :
    _id(id)
{}

Id ReportItem::GetId() const
{
    return _id;
}

TaskShp ReportItem::GetTask() const
{
    return _task;
}

void ReportItem::SetTask(const TaskShp& task)
{
    _task = task;
}

ReportItemTypeShp ReportItem::GetType() const
{
    return _type;
}

void ReportItem::SetType(const ReportItemTypeShp& type)
{
    _type = type;
}

QTime ReportItem::GetStart() const
{
    return _start;
}

void ReportItem::SetStart(const QTime& start)
{
    _start = start;
}

QTime ReportItem::GetEnd() const
{
    return _end;
}

void ReportItem::SetEnd(const QTime& end)
{
    _end = end;
}

QString ReportItem::GetText() const
{
    return _text;
}

void ReportItem::SetText(const QString& text)
{
    _text = text;
}
