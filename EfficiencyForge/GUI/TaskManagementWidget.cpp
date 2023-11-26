#include "TaskManagementWidget.h"
#include "ui_TaskManagementWidget.h"

TaskManagementWidget::TaskManagementWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskManagementWidget)
{
    ui->setupUi(this);
}

TaskManagementWidget::~TaskManagementWidget()
{
    delete ui;
}
