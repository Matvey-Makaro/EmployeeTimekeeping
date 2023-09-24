#include "TaskRecordWidget.h"
#include "ui_TaskRecordWidget.h"

TaskRecordWidget::TaskRecordWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskRecordWidget)
{
    ui->setupUi(this);
}

TaskRecordWidget::~TaskRecordWidget()
{
    delete ui;
}
