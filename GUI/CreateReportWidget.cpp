#include "CreateReportWidget.h"
#include "ui_CreateReportWidget.h"

CreateReportWidget::CreateReportWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateReportWidget)
{
    ui->setupUi(this);
}

CreateReportWidget::~CreateReportWidget()
{
    delete ui;
}
