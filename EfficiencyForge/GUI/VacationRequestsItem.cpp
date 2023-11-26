#include "VacationRequestsItem.h"
#include "ui_VacationRequestsItem.h"

VacationRequestsItem::VacationRequestsItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VacationRequestsItem)
{
    ui->setupUi(this);
}

VacationRequestsItem::~VacationRequestsItem()
{
    delete ui;
}
