#include "BusinessTripListWidget.h"
#include "ui_BusinessTripListWidget.h"

BusinessTripListWidget::BusinessTripListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BusinessTripListWidget)
{
    ui->setupUi(this);
}

BusinessTripListWidget::~BusinessTripListWidget()
{
    delete ui;
}
