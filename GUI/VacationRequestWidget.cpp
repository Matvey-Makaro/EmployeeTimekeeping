#include "VacationRequestWidget.h"
#include "ui_VacationRequestWidget.h"

VacationRequestWidget::VacationRequestWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VacationRequestWidget)
{
    ui->setupUi(this);
}

VacationRequestWidget::~VacationRequestWidget()
{
    delete ui;
}
