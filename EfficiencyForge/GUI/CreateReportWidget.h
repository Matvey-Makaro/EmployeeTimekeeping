#pragma once

#include <QWidget>
#include "Entities/Report/Report.h"
#include "Entities/User.h"
#include "ViewModels/ReportTableViewModel.h"

namespace Ui {
class CreateReportWidget;
}

// TODO: Rename to ReportEditingWidget
class CreateReportWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CreateReportWidget(ReportShp report,
                                UserShp currUser,
                                QVector<ReportItemTypeShp> itemTypes,
                                QWidget *parent = nullptr);
    ~CreateReportWidget();

    ReportShp GetReport() const;

    QVector<ReportItemTypeShp> GetReportItemTypes() const;
    void SetReportItemTypes(const QVector<ReportItemTypeShp>& reportItemTypes);

signals:
    void Saving(const ReportShp&);

private slots:
    void on_addBtn_clicked();
    void on_deleteBtn_clicked();

    void on_saveBtn_clicked();

private:
    void SetupUi();

private:
    Ui::CreateReportWidget *_ui;
    ReportTableViewModel* _reportViewModel;
    ReportShp _report;
    UserShp _currUser;
    QVector<ReportItemTypeShp> _reportItemTypes;
};

