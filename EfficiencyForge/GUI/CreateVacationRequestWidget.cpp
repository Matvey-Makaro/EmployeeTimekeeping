#include "CreateVacationRequestWidget.h"
#include "ui_CreateVacationRequestWidget.h"

CreateVacationRequestWidget::CreateVacationRequestWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateVacationRequestWidget)
{
    ui->setupUi(this);
}

CreateVacationRequestWidget::~CreateVacationRequestWidget()
{
    delete ui;
}
