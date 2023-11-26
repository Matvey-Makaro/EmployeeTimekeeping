#pragma once

#include <QWidget>

namespace Ui {
class ReportHistory;
}

class ReportHistoryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReportHistoryWidget(QWidget *parent = nullptr);
    ~ReportHistoryWidget();

private:
    Ui::ReportHistory *ui;
};

