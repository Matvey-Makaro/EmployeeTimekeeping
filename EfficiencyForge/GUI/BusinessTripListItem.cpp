#include "BusinessTripListItem.h"
#include "ui_BusinessTripListItem.h"

BusinessTripListItem::BusinessTripListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BusinessTripListItem)
{
    ui->setupUi(this);
}

BusinessTripListItem::~BusinessTripListItem()
{
    delete ui;
}
