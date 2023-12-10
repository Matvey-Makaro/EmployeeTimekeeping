#include <QTimeEdit>
#include <QComboBox>
#include <QLineEdit>
#include "ReportTableViewModel.h"
#include "ReportItemDelegate.h"
#include "TypeTraits.h"

ReportItemDelegate::ReportItemDelegate(QObject* parent) :
    QStyledItemDelegate(parent)
{}

QWidget* ReportItemDelegate::createEditor(QWidget* parent,
                                          const QStyleOptionViewItem& option,
                                          const QModelIndex& index) const
{
    if(index.column() == ReportTableViewModel::Cols::StartTime ||
            index.column() == ReportTableViewModel::Cols::EndTime)
    {
        QTimeEdit* timeEdit = new QTimeEdit(parent);
        //        timeEdit->setFrame(false);
        return timeEdit;
    }
    else if(index.column() == ReportTableViewModel::Cols::Text)
    {
        QLineEdit* lineEdit = new QLineEdit(parent);
        return lineEdit;
    }
    else if(index.column() == ReportTableViewModel::Cols::TypeName)
    {
        QComboBox* comboBox = new QComboBox(parent);
        for(const auto& i : qAsConst(_itemTypes))
            comboBox->addItem(i.second->GetName(), i.first);
        return comboBox;
    }
    else if(index.column() == ReportTableViewModel::Cols::TaskName)
    {
        QComboBox* comboBox = new QComboBox(parent);
        for(const auto& t : qAsConst(_tasks))
            comboBox->addItem(t.second->GetName(), t.first);
        return comboBox;
    }
    Q_ASSERT(false);
    return nullptr;
}

void ReportItemDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
    if(index.column() == ReportTableViewModel::Cols::StartTime ||
            index.column() == ReportTableViewModel::Cols::EndTime)
    {
        QTime time = index.model()->data(index, Qt::EditRole).toTime();
        QTimeEdit* timeEdit = static_cast<QTimeEdit*>(editor);
        timeEdit->setTime(time);
        return;
    }
    else if(index.column() == ReportTableViewModel::Cols::Text)
    {
        QString text = index.model()->data(index, Qt::EditRole).toString();
        QLineEdit* lineEdit = static_cast<QLineEdit*>(editor);
        lineEdit->setText(text);
        return;
    }
    else if(index.column() == ReportTableViewModel::Cols::TypeName)
    {
        Id itemTypeId = index.model()->data(index, Qt::EditRole).toLongLong();
        if(itemTypeId == InvalidId)
            itemTypeId = _itemTypes.begin()->first;
        QComboBox* comboBox = static_cast<QComboBox*>(editor);
        comboBox->setCurrentText(_itemTypes.at(itemTypeId)->GetName());
    }
    else if(index.column() == ReportTableViewModel::Cols::TaskName)
    {
        Id taskId = index.model()->data(index, Qt::EditRole).toLongLong();
        if(taskId == InvalidId)
            return;
        QComboBox* comboBox = static_cast<QComboBox*>(editor);
        comboBox->setCurrentText(_tasks.at(taskId)->GetName());
    }
}

void ReportItemDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
    if(index.column() == ReportTableViewModel::Cols::StartTime ||
            index.column() == ReportTableViewModel::Cols::EndTime)
    {
        QTimeEdit* timeEdit = static_cast<QTimeEdit*>(editor);
        timeEdit->interpretText();
        QTime time = timeEdit->time();

        model->setData(index, time, Qt::EditRole);
        return;
    }
    else if(index.column() == ReportTableViewModel::Cols::Text)
    {
        QLineEdit* lineEdit = static_cast<QLineEdit*>(editor);
        QString text = lineEdit->text();

        model->setData(index, text, Qt::EditRole);
        return;
    }
    else if(index.column() == ReportTableViewModel::Cols::TypeName ||
            index.column() == ReportTableViewModel::Cols::TaskName)
    {
        QComboBox* comboBox = static_cast<QComboBox*>(editor);
        Id id = comboBox->currentData().toLongLong();
        model->setData(index, id, Qt::EditRole);
    }
}

void ReportItemDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    if(!index.isValid())
        return;
    editor->setGeometry(option.rect);
}

void ReportItemDelegate::SetItemTypes(const QVector<ReportItemTypeShp>& itemTypes)
{
    _itemTypes.clear();
    for(const auto& i : itemTypes)
        _itemTypes[i->GetId()] = i;
}

void ReportItemDelegate::SetTasks(const QVector<TaskShp>& tasks)
{
    _tasks.clear();
    for(const auto& t : tasks)
        _tasks[t->GetId()] = t;
}
