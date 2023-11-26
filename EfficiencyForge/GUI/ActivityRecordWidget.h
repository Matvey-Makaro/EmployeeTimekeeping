#pragma once

#include <QWidget>

namespace Ui {
class ActivityRecordWidget;
}

class ActivityRecordWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ActivityRecordWidget(QWidget *parent = nullptr);
    ~ActivityRecordWidget();

private:
    Ui::ActivityRecordWidget *ui;
};

