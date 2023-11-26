#pragma once

#include <QWidget>

namespace Ui {
class ShowWorkScheduleWidget;
}

class ShowWorkScheduleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShowWorkScheduleWidget(QWidget *parent = nullptr);
    ~ShowWorkScheduleWidget();

private:
    Ui::ShowWorkScheduleWidget *ui;
};

