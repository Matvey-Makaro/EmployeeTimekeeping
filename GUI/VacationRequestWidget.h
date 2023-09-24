#pragma once

#include <QWidget>

namespace Ui {
class VacationRequestWidget;
}

class VacationRequestWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VacationRequestWidget(QWidget *parent = nullptr);
    ~VacationRequestWidget();

private:
    Ui::VacationRequestWidget *ui;
};

