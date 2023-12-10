#include "Entities/Report/ReportItem.h"
#include "ViewModels/ReportItemDelegate.h"
#include "CreateReportWidget.h"
#include "ui_CreateReportWidget.h"

CreateReportWidget::CreateReportWidget(ReportShp report,
                                       UserShp currUser,
                                       QVector<ReportItemTypeShp> itemTypes,
                                       QWidget* parent) :
    QWidget(parent),
    _ui(new Ui::CreateReportWidget),
    _reportViewModel(new ReportTableViewModel(this)),
    _report(std::move(report)),
    _currUser(std::move(currUser)),
    _reportItemTypes(std::move(itemTypes))
{
    Q_ASSERT_X(!_report.isNull(), "CreateReportWidget::CreateReportWidget",
               "_report.isNull()");

    SetupUi();
    // TODO: Disable if _report.isNull();


}

CreateReportWidget::~CreateReportWidget()
{
    delete _ui;
}

ReportShp CreateReportWidget::GetReport() const
{
    // TODO: Update report

    return _report;
}

void CreateReportWidget::on_addBtn_clicked()
{
    auto reportItem = ReportItemShp::create();
    QTime startTime = _ui->startTimeEdit->time();
    QTime endTime = _ui->endTimeEdit->time();
    reportItem->SetStart(startTime);
    reportItem->SetEnd(endTime);
    reportItem->SetText("Text");
    _reportViewModel->PushBackItem(reportItem);
}

void CreateReportWidget::SetupUi()
{
    _ui->setupUi(this);

    _reportViewModel->SetItemTypes(_reportItemTypes);

    ReportItemDelegate* delegate = new ReportItemDelegate(_ui->tableView);
    delegate->SetItemTypes(_reportItemTypes);
    _ui->tableView->setModel(_reportViewModel);
    _ui->tableView->setItemDelegate(delegate);
    _ui->tableView->setEditTriggers(QTableView::DoubleClicked);

    _ui->dateEdit->setDate(_report->GetDate());
    _ui->startTimeEdit->setTime(_report->GetStartWorkingDay());
    _ui->endTimeEdit->setTime(_report->GetEndWorkingDay());

    _reportViewModel->SetItems(_report->GetItems());
}

QVector<ReportItemTypeShp> CreateReportWidget::GetReportItemTypes() const
{
    return _reportItemTypes;
}

void CreateReportWidget::SetReportItemTypes(const QVector<ReportItemTypeShp>& reportItemTypes)
{
    _reportItemTypes = reportItemTypes;
}

void CreateReportWidget::on_deleteBtn_clicked()
{
    auto index = _ui->tableView->currentIndex();
    if(!index.isValid())
        return;
    _reportViewModel->DeleteRow(index.row());
}

void CreateReportWidget::on_saveBtn_clicked()
{
    _report->SetDate(_ui->dateEdit->date());
    _report->SetStartWorkingDay(_ui->startTimeEdit->time());
    _report->SetEndWorkingDay(_ui->endTimeEdit->time());
    _report->SetItems(_reportViewModel->GetItems());
    emit Saving(_report);
}
