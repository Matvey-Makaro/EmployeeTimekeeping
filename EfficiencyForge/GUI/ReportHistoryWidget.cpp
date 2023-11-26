#include "ReportHistoryWidget.h"
#include "ui_ReportHistoryWidget.h"

ReportHistoryWidget::ReportHistoryWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportHistory)
{
    ui->setupUi(this);
}

ReportHistoryWidget::~ReportHistoryWidget()
{
    delete ui;
}
