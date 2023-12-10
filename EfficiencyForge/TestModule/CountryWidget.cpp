#include "CountryWidget.h"
#include "ui_CountryWidget.h"

CountryWidget::CountryWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CountryWidget)
{
    ui->setupUi(this);
}

QTableView* CountryWidget::GetTableView()
{
    return ui->tableView;
}

CountryWidget::~CountryWidget()
{
    delete ui;
}
