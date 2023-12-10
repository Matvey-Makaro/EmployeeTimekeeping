#include <QDebug>
#include "Entities/Task/Task.h"
#include "ReportTableViewModel.h"

ReportTableViewModel::ReportTableViewModel(QObject* parent) :
    QAbstractTableModel(parent)
{

}

int ReportTableViewModel::rowCount(const QModelIndex&) const
{
    return _items.size();
}

int ReportTableViewModel::columnCount(const QModelIndex&) const
{
    return NumOfCols;
}

QVariant ReportTableViewModel::data(const QModelIndex& index, int role) const
{
    if(!index.isValid())
        return QVariant();

    QVariant value;
    const auto& item = _items[index.row()];
    if(item.isNull())
        return value;

    if(role == Qt::DisplayRole)
    {
        qDebug() << "ReportTableViewModel::data()" << "itemId:" << item->GetId() << "type: " << item->GetType();
        if(index.column() == StartTime)
        {
            value = item->GetStart();
        }
        else if(index.column() == EndTime)
        {
            value = item->GetEnd();
        }
        else if(index.column() == Text)
        {
            value = item->GetText();
        }
        else if(index.column() == TypeName)
        {
            const auto& type = item->GetType();
            if(!type.isNull())
                value = type->GetName();
        }
        else if(index.column() == TaskName)
        {
            const auto& task = item->GetTask();
            if(!task.isNull())
                value = task->GetName();
        }
    }
    else if(role == Qt::EditRole)
    {
        if(index.column() == StartTime)
        {
            value = item->GetStart();
        }
        else if(index.column() == EndTime)
        {
            value = item->GetEnd();
        }
        else if(index.column() == Text)
        {
            value = item->GetText();
        }
        else if(index.column() == TypeName)
        {
            const auto& type = item->GetType();
            if(!type.isNull())
                value = type->GetId();
            else value = InvalidId;
        }
        else if(index.column() == TaskName)
        {
            const auto& task = item->GetTask();
            if(!task.isNull())
                value = task->GetId();
            else value = InvalidId;
        }
    }
    return value;
}

Qt::ItemFlags ReportTableViewModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool ReportTableViewModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    const auto& item = _items[index.row()];
    if(item.isNull())
        return false;

    if(role == Qt::EditRole)
    {
        if(index.column() == StartTime)
        {
            item->SetStart(value.toTime());
        }
        else if(index.column() == EndTime)
        {
            item->SetEnd(value.toTime());
        }
        else if(index.column() == Text)
        {
            item->SetText(value.toString());
        }
        else if(index.column() == TypeName)
        {
            Id id = value.toLongLong();
            item->SetType(_itemTypes[id]);
        }
        else if(index.column() == TaskName)
        {
            Id id = value.toLongLong();
            item->SetTask(_tasks[id]);
        }
        return true;
    }
    return false;
}

QVariant ReportTableViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        return ToStr(static_cast<Cols>(section));
    }
    return QVariant();
}

QVector<ReportItemShp> ReportTableViewModel::GetItems() const
{
    return _items;
}

void ReportTableViewModel::SetItems(const QVector<ReportItemShp>& items)
{
    beginInsertRows(QModelIndex(), 0, items.size() - 1);
    _items = items;
    endInsertRows();
}

void ReportTableViewModel::PushBackItem(ReportItemShp i)
{
    beginInsertRows(QModelIndex(), _items.size(), _items.size());
    _items.push_back(std::move(i));
    endInsertRows();
}

void ReportTableViewModel::DeleteRow(int idx)
{
    beginRemoveRows(QModelIndex(), idx, idx);
    _items.remove(idx);
    endRemoveRows();
}

QString ReportTableViewModel::ToStr(ReportTableViewModel::Cols col) const
{
    if(col == StartTime)
        return "С";
    else if(col == EndTime)
        return "По";
    else if(col == Text)
        return "Занятие";
    else if(col == TypeName)
        return "Вид работы";
    else if(col == TaskName)
        return "Задача";
    Q_ASSERT(false);
    return "Unknown";

}

std::map<Id, TaskShp> ReportTableViewModel::GetTasks() const
{
    return _tasks;
}

void ReportTableViewModel::SetTasks(const QVector<TaskShp>& tasks)
{
    _tasks.clear();
    for(const auto& t : tasks)
        _tasks[t->GetId()] = t;
}

const std::map<Id, ReportItemTypeShp>& ReportTableViewModel::GetItemTypes() const
{
    return _itemTypes;
}

void ReportTableViewModel::SetItemTypes(const QVector<ReportItemTypeShp>& itemTypes)
{
    _itemTypes.clear();
    for(const auto& i : itemTypes)
        _itemTypes[i->GetId()] = i;
}
