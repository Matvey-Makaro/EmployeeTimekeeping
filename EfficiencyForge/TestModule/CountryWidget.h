#pragma once

#include <QWidget>
#include <QTableView>

namespace Ui {
class CountryWidget;
}

class CountryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CountryWidget(QWidget *parent = nullptr);
    QTableView* GetTableView();
    ~CountryWidget();

private:
    Ui::CountryWidget *ui;
};

