#pragma once

#include <QMainWindow>
#include <QSharedPointer>
#include <QWidget>
#include <map>
#include "Entities/User.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum Tabs
{
    None,
    ReportHistory,
    CreateReport,
};

class ReportHistoryWidget;
class CreateReportWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(UserShp user, QWidget *parent = nullptr);
    ~MainWindow();

    const ReportHistoryWidget* GetReportHistoryWidget() const;
    const CreateReportWidget* GetCreateReportWidget() const;

private:
    void FillTabToWidget();
    void FillStackedWidget();

private:
    Ui::MainWindow *ui;
    UserShp _user;
    std::map<Tabs, QWidget*> _tabToWidget;
};
using MainWindowShp = QSharedPointer<MainWindow>;
