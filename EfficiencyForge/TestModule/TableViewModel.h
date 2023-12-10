#pragma once

#include <QAbstractListModel>
#include "CountryFlag.h"

class TableViewModel : public QAbstractListModel
{
public:
    TableViewModel(QObject* parent = nullptr);
    int rowCount(const QModelIndex &) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    void populate(QList<CountryFlag> *newValues);

    void append(CountryFlag value);
    void update(int idx, CountryFlag value);
    void deleteRow(int idx);
    void insertAt(int idx, CountryFlag value);
private:
    QList<CountryFlag> *values;
};

