#include "ShowBusinessTripWidget.h"
#include "ui_ShowBusinessTripWidget.h"

ShowBusinessTripWidget::ShowBusinessTripWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowBusinessTripWidget)
{
    ui->setupUi(this);
}

ShowBusinessTripWidget::~ShowBusinessTripWidget()
{
    delete ui;
}
