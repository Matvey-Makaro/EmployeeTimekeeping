#pragma once

#include <QWidget>

namespace Ui {
class CreateReportWidget;
}

class CreateReportWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CreateReportWidget(QWidget *parent = nullptr);
    ~CreateReportWidget();

private:
    Ui::CreateReportWidget *ui;
};

