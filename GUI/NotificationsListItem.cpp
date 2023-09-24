#include "NotificationsListItem.h"
#include "ui_NotificationsListItem.h"

NotificationsListItem::NotificationsListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotificationsListItem)
{
    ui->setupUi(this);
}

NotificationsListItem::~NotificationsListItem()
{
    delete ui;
}
