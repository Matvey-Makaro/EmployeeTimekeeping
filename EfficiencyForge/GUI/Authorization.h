#pragma once

#include <QWidget>
#include <QSharedPointer>
#include <QString>

namespace Ui {
class Authorization;
}

class Authorization : public QWidget
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = nullptr);
    ~Authorization();

protected slots:
    void on_EnterButton_clicked();

signals:
    void TryingLogIn(const QString& login, const QString& password);

protected:
    Ui::Authorization *ui;
};

using AuthorizationShp = QSharedPointer<Authorization>;
