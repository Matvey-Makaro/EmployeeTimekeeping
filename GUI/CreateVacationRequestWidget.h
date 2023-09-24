#pragma once

#include <QWidget>

namespace Ui {
class CreateVacationRequestWidget;
}

class CreateVacationRequestWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CreateVacationRequestWidget(QWidget *parent = nullptr);
    ~CreateVacationRequestWidget();

private:
    Ui::CreateVacationRequestWidget *ui;
};

