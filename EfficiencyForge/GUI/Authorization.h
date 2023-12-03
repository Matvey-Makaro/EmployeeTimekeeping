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

signals:
    void TryingLogIn(const QString& login, const QString& password);

protected slots:
    void on_EnterButton_clicked();

protected:
    Ui::Authorization *ui;
};

using AuthorizationShp = QSharedPointer<Authorization>;
