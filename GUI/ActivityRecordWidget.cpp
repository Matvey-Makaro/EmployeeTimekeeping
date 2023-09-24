#include "ActivityRecordWidget.h"
#include "ui_ActivityRecordWidget.h"

ActivityRecordWidget::ActivityRecordWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActivityRecordWidget)
{
    ui->setupUi(this);
}

ActivityRecordWidget::~ActivityRecordWidget()
{
    delete ui;
}
