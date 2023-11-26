#pragma once

#include <QWidget>

namespace Ui {
class ShowNotificationWidget;
}

class ShowNotificationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShowNotificationWidget(QWidget *parent = nullptr);
    ~ShowNotificationWidget();

private:
    Ui::ShowNotificationWidget *ui;
};

