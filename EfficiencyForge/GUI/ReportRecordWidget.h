#pragma once

#include <QWidget>

namespace Ui {
class ReportRecordWidget;
}

class ReportRecordWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReportRecordWidget(QWidget *parent = nullptr);
    ~ReportRecordWidget();

private:
    Ui::ReportRecordWidget *ui;
};

