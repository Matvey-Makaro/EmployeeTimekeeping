#include "CreateReportWidget.h"
#include "ReportHistoryWidget.h"

#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(UserShp user, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _user(std::move(user))
{
    ui->setupUi(this);

    ui->employeeNameLabel->setText(_user->GetShortFullName());
}

MainWindow::~MainWindow()
{
    delete ui;
}

const ReportHistoryWidget* MainWindow::GetReportHistoryWidget() const
{
    QWidget* widget = _tabToWidget.at(Tabs::ReportHistory);
    return dynamic_cast<ReportHistoryWidget*>(widget);
}

const CreateReportWidget* MainWindow::GetCreateReportWidget() const
{
    QWidget* widget = _tabToWidget.at(Tabs::CreateReport);
    return dynamic_cast<CreateReportWidget*>(widget);
}

void MainWindow::FillTabToWidget()
{
    _tabToWidget[Tabs::None] = new QWidget(this);
    _tabToWidget[Tabs::CreateReport] = new  CreateReportWidget(this);
    _tabToWidget[Tabs::ReportHistory] = new  ReportHistoryWidget(this);

}

void MainWindow::FillStackedWidget()
{
    // TODO: Check user role
    for(const auto& [tab, widget] : _tabToWidget)
        ui->stackedWidget->insertWidget(tab, widget);
}

