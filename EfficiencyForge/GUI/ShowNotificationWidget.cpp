#include "ShowNotificationWidget.h"
#include "ui_ShowNotificationWidget.h"

ShowNotificationWidget::ShowNotificationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowNotificationWidget)
{
    ui->setupUi(this);
}

ShowNotificationWidget::~ShowNotificationWidget()
{
    delete ui;
}
