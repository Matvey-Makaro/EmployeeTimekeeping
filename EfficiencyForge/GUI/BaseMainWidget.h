#pragma once

#include <QWidget>
#include <QSharedPointer>
#include <map>
#include "Entities/User.h"
#include "App/DataPool.h"

namespace Ui {
class BaseMainWidget;
}

enum Tabs
{
    None,
    ReportHistory,
    CreateReport,
};

class ReportHistoryWidget;
class CreateReportWidget;

class BaseMainWidget : public QWidget
{
    Q_OBJECT
public:
    BaseMainWidget(UserShp user, QWidget *parent = nullptr);
    ~BaseMainWidget();

    const ReportHistoryWidget* GetReportHistoryWidget() const;
    const CreateReportWidget* GetCreateReportWidget() const;

    DataPoolShp GetDataPool() const;
    void SetDataPool(const DataPoolShp& dataPool);

private slots:
    void on_reportHistoryBtn_clicked();
    void on_createReportBtn_clicked();

private:
    void FillTabToWidget();
    void FillStackedWidget();

private:
    Ui::BaseMainWidget *ui;
    UserShp _user;
    std::map<Tabs, QWidget*> _tabToWidget;
    DataPoolShp _dataPool;
};
using BaseMainWidgetShp = QSharedPointer<BaseMainWidget>;

