#include "ShowWorkScheduleWidget.h"
#include "ui_ShowWorkScheduleWidget.h"

ShowWorkScheduleWidget::ShowWorkScheduleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowWorkScheduleWidget)
{
    ui->setupUi(this);
}

ShowWorkScheduleWidget::~ShowWorkScheduleWidget()
{
    delete ui;
}
