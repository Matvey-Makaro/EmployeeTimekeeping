#pragma once

#include <QWidget>

namespace Ui {
class BusinessTripListItem;
}

class BusinessTripListItem : public QWidget
{
    Q_OBJECT

public:
    explicit BusinessTripListItem(QWidget *parent = nullptr);
    ~BusinessTripListItem();

private:
    Ui::BusinessTripListItem *ui;
};

