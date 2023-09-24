#pragma once

#include <QWidget>

namespace Ui {
class NotificationsListWidget;
}

class NotificationsListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NotificationsListWidget(QWidget *parent = nullptr);
    ~NotificationsListWidget();

private:
    Ui::NotificationsListWidget *ui;
};

