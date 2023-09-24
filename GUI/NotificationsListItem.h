#pragma once

#include <QWidget>

namespace Ui {
class NotificationsListItem;
}

class NotificationsListItem : public QWidget
{
    Q_OBJECT

public:
    explicit NotificationsListItem(QWidget *parent = nullptr);
    ~NotificationsListItem();

private:
    Ui::NotificationsListItem *ui;
};

