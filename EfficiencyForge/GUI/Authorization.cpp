#include "Authorization.h"
#include "ui_Authorization.h"

Authorization::Authorization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Authorization)
{
    ui->setupUi(this);
}

Authorization::~Authorization()
{
    delete ui;
}

void Authorization::on_EnterButton_clicked()
{
    QString login = ui->LoginLineEdit->text();
    QString password = ui->PasswordLineEdit->text();
    emit TryingLogIn(login, password);
}
