#pragma once

#include <QWidget>

namespace Ui {
class ShowBusinessTripWidget;
}

class ShowBusinessTripWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShowBusinessTripWidget(QWidget *parent = nullptr);
    ~ShowBusinessTripWidget();

private:
    Ui::ShowBusinessTripWidget *ui;
};

