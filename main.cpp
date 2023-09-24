#include "GUI/MainWindow..h"
#include "GUI/Authorization.h"
#include "GUI/CreateReportWidget.h"
#include "GUI/ActivityRecordWidget.h"
#include "GUI/ReportRecordWidget.h"
#include "GUI/ReportHistoryWidget.h"
#include "GUI/TaskRecordWidget.h"
#include "GUI/TaskManagementWidget.h"
#include "GUI/ShowTaskWidget.h"
#include "GUI/NotificationsListWidget.h"
#include "GUI/ShowNotificationWidget.h"
#include "GUI/VacationRequestWidget.h"
#include "GUI/CreateVacationRequestWidget.h"
#include "GUI/BusinessTripListWidget.h"
#include "GUI/ShowBusinessTripWidget.h"
#include "GUI/ShowWorkScheduleWidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    Authorization auth;
//    auth.show();

//    CreateReportWidget createReportWidget;
//    createReportWidget.show();

//    ActivityRecordWidget activityRecordWidget;
//    activityRecordWidget.show();

//    ReportRecordWidget reportRecordWidget;
//    reportRecordWidget.show();

//    ReportHistoryWidget reportHistory;
//    reportHistory.show();

//    TaskRecordWidget taskRecordWidget;
//    taskRecordWidget.show();

//    TaskManagementWidget taskManagementWidget;
//    taskManagementWidget.show();

//    ShowTaskWidget showTaskWidget;
//    showTaskWidget.show();

//    NotificationsListWidget notificationListWidget;
//    notificationListWidget.show();

//    ShowNotificationWidget showNotificationWidget;
//    showNotificationWidget.show();

//    VacationRequestWidget vacationRequestWidget;
//    vacationRequestWidget.show();

//    CreateVacationRequestWidget createVacationRequestWidget;
//    createVacationRequestWidget.show();

//    BusinessTripListWidget businessTripListWidget;
//    businessTripListWidget.show();

//    ShowBusinessTripWidget showBusinessTripWidget;
//    showBusinessTripWidget.show();

    ShowWorkScheduleWidget showWorkScheduleWidget;
    showWorkScheduleWidget.show();

    return a.exec();
}
