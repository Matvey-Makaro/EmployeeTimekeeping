#include <QDebug>
#include <QKeyEvent>
#include "Authorization.h"
#include "ui_Authorization.h"

#define DEBUG

Authorization::Authorization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Authorization)
{
    ui->setupUi(this);

#ifdef DEBUG
    ui->LoginLineEdit->setText("login");
    ui->PasswordLineEdit->setText("password");
#endif
}

Authorization::~Authorization()
{
    delete ui;
}

void Authorization::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Return)
        on_EnterButton_clicked();
    QWidget::keyPressEvent(event);
}

void Authorization::on_EnterButton_clicked()
{
    QString login = ui->LoginLineEdit->text();
    QString password = ui->PasswordLineEdit->text();
    emit TryingLogIn(login, password);
}
