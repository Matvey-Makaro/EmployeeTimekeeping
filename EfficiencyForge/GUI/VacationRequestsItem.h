#pragma once

#include <QWidget>

namespace Ui {
class VacationRequestsItem;
}

class VacationRequestsItem : public QWidget
{
    Q_OBJECT

public:
    explicit VacationRequestsItem(QWidget *parent = nullptr);
    ~VacationRequestsItem();

private:
    Ui::VacationRequestsItem *ui;
};

