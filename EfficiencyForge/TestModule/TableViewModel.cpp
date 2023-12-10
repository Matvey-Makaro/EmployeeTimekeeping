#include "TableViewModel.h"


TableViewModel::TableViewModel(QObject* parent) :
    QAbstractListModel(parent)
{
    values = new QList<CountryFlag>();
}

int TableViewModel::rowCount(const QModelIndex&) const
{
    return values->size();
}

int TableViewModel::columnCount(const QModelIndex& parent) const
{
    return 3;
}

QVariant TableViewModel::data(const QModelIndex& index, int role) const
{
    QVariant value;
    if(role == Qt::DisplayRole)
    {
        if(index.column() == 0)
            value = values->at(index.row()).getId();
        else if(index.column() == 1)
            value = values->at(index.row()).getName();
        else if(index.column() == 2)
            value = values->at(index.row()).getIcon();
    }
    else if(role == Qt::UserRole)
        value = values->at(index.row()).getId();
    return value;
}

void TableViewModel::populate(QList<CountryFlag>* newValues)
{
    int idx = this->values->count();
    beginInsertRows(QModelIndex(), 1, idx);
    values = newValues;
    endInsertRows();
}

void TableViewModel::append(CountryFlag value)
{
    int newRow = this->values->count()+1;

    this->beginInsertRows(QModelIndex(), newRow, newRow);
    values->append(value);
    endInsertRows();
}

void TableViewModel::update(int idx, CountryFlag value)
{
    (*this->values)[idx] = value;

    QModelIndex item_idx_s = index(idx, 0);
    QModelIndex item_idx_e = this->index(idx,this->columnCount(QModelIndex()));

    emit this->dataChanged(item_idx_s ,item_idx_e );
}

void TableViewModel::deleteRow(int idx)
{
    beginRemoveRows(QModelIndex(), idx, idx);
    (*this->values).removeAt(idx);
    this->endRemoveRows();
}

void TableViewModel::insertAt(int idx, CountryFlag value)
{
    int newRow = idx;

    this->beginInsertRows(QModelIndex(), newRow, newRow);

    values->insert(newRow,value);

    endInsertRows();
}
