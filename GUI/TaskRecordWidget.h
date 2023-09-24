#pragma once

#include <QWidget>

namespace Ui {
class TaskRecordWidget;
}

class TaskRecordWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TaskRecordWidget(QWidget *parent = nullptr);
    ~TaskRecordWidget();

private:
    Ui::TaskRecordWidget *ui;
};

