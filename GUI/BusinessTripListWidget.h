#pragma once

#include <QWidget>

namespace Ui {
class BusinessTripListWidget;
}

class BusinessTripListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BusinessTripListWidget(QWidget *parent = nullptr);
    ~BusinessTripListWidget();

private:
    Ui::BusinessTripListWidget *ui;
};

