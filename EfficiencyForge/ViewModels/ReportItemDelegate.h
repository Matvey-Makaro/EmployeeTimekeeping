#pragma once

#include <QStyledItemDelegate>
#include <map>
#include "Entities/Report/ReportItemType.h"
#include "Entities/Task/Task.h"
#include "TypeTraits.h"

class ReportItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    ReportItemDelegate(QObject* parent = nullptr);

    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;

    void SetItemTypes(const QVector<ReportItemTypeShp>& itemTypes);
    void SetTasks(const QVector<TaskShp>& tasks);

private:
    std::map<Id, ReportItemTypeShp> _itemTypes;
    std::map<Id, TaskShp> _tasks;
};

