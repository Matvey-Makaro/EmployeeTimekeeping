#pragma once

#include <QWidget>

namespace Ui {
class ShowTaskWidget;
}

class ShowTaskWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShowTaskWidget(QWidget *parent = nullptr);
    ~ShowTaskWidget();

private:
    Ui::ShowTaskWidget *ui;
};

