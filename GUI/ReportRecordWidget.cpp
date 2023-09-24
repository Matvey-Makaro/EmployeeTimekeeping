#include "ReportRecordWidget.h"
#include "ui_ReportRecordWidget.h"

ReportRecordWidget::ReportRecordWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportRecordWidget)
{
    ui->setupUi(this);
}

ReportRecordWidget::~ReportRecordWidget()
{
    delete ui;
}
