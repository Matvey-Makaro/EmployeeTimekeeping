#pragma once

#include <QAbstractTableModel>
#include <QVector>
#include <map>
#include "Entities/Report/ReportItem.h"

class ReportTableViewModel : public QAbstractTableModel
{
public:
    enum Cols
    {
        StartTime = 0,
        EndTime = 1,
        Text = 2,
        TypeName = 3,
        TaskName = 4,
        NumOfCols
    };

    ReportTableViewModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex &) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;


    QVector<ReportItemShp> GetItems() const;
    void SetItems(const QVector<ReportItemShp>& items);

    void PushBackItem(ReportItemShp i);
    void DeleteRow(int idx);

    const std::map<Id, ReportItemTypeShp>& GetItemTypes() const;
    void SetItemTypes(const QVector<ReportItemTypeShp>& itemTypes);

    std::map<Id, TaskShp> GetTasks() const;
    void SetTasks(const QVector<TaskShp>& tasks);

private:
    QString ToStr(Cols col) const;

private:
    QVector<ReportItemShp> _items;
    std::map<Id, ReportItemTypeShp> _itemTypes;
    std::map<Id, TaskShp> _tasks;
};

