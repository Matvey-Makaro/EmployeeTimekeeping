#include "ShowTaskWidget.h"
#include "ui_ShowTaskWidget.h"

ShowTaskWidget::ShowTaskWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowTaskWidget)
{
    ui->setupUi(this);
}

ShowTaskWidget::~ShowTaskWidget()
{
    delete ui;
}
