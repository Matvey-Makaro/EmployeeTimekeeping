#include "NotificationsListWidget.h"
#include "ui_NotificationsListWidget.h"

NotificationsListWidget::NotificationsListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotificationsListWidget)
{
    ui->setupUi(this);
}

NotificationsListWidget::~NotificationsListWidget()
{
    delete ui;
}
