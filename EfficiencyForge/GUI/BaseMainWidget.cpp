#include "CreateReportWidget.h"
#include "ReportHistoryWidget.h"

#include "BaseMainWidget.h"
#include "ui_BaseMainWidget.h"

BaseMainWidget::BaseMainWidget(UserShp user, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BaseMainWidget)
    , _user(std::move(user))
{
    ui->setupUi(this);

    ui->employeeNameLabel->setText(_user->GetShortFullName());
    FillTabToWidget();
    FillStackedWidget();
}

BaseMainWidget::~BaseMainWidget()
{
    delete ui;
}

const ReportHistoryWidget* BaseMainWidget::GetReportHistoryWidget() const
{
    QWidget* widget = _tabToWidget.at(Tabs::ReportHistory);
    return dynamic_cast<ReportHistoryWidget*>(widget);
}

const CreateReportWidget* BaseMainWidget::GetCreateReportWidget() const
{
    QWidget* widget = _tabToWidget.at(Tabs::CreateReport);
    return dynamic_cast<CreateReportWidget*>(widget);
}

void BaseMainWidget::FillTabToWidget()
{
    _tabToWidget[Tabs::None] = new QWidget(this);
    // TODO:
    _tabToWidget[Tabs::CreateReport] = new CreateReportWidget(Report::CreateEmpty(),
                                                              _user,
                                                              {},
                                                              {},
                                                              this);
    _tabToWidget[Tabs::ReportHistory] = new  ReportHistoryWidget(this);

}

void BaseMainWidget::FillStackedWidget()
{
    // TODO: Check user role
    for(const auto& [tab, widget] : _tabToWidget)
        ui->stackedWidget->insertWidget(tab, widget);
}

DataPoolShp BaseMainWidget::GetDataPool() const
{
    return _dataPool;
}

void BaseMainWidget::SetDataPool(const DataPoolShp& dataPool)
{
    _dataPool = dataPool;
}

void BaseMainWidget::on_reportHistoryBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(Tabs::ReportHistory);
}

void BaseMainWidget::on_createReportBtn_clicked()
{
    auto it = _tabToWidget.find(Tabs::CreateReport);
    if(it != _tabToWidget.end())
    {
        if(it->second != nullptr)
        {
            delete it->second;
            it->second = nullptr;
        }
    }
    auto* widget = new CreateReportWidget(Report::CreateEmpty(),
                                          _user,
                                          _dataPool->GetReportItemTypes(),
                                          _dataPool->GetTasksByAssigneeId(_user->GetId()),
                                          this);

    connect(widget, &CreateReportWidget::Saving, this, &BaseMainWidget::OnSaveReport);

    _tabToWidget[Tabs::CreateReport] = widget;
    ui->stackedWidget->insertWidget(Tabs::CreateReport, widget);
    ui->stackedWidget->setCurrentIndex(Tabs::CreateReport);
}

void BaseMainWidget::OnSaveReport(const ReportShp& report)
{
    emit SavingReport(report);
}
