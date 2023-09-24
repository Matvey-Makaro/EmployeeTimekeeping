QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GUI/ActivityRecordWidget.cpp \
    GUI/Authorization.cpp \
    GUI/BusinessTripListWidget.cpp \
    GUI/CreateReportWidget.cpp \
    GUI/CreateVacationRequestWidget.cpp \
    GUI/MainWindow..cpp \
    GUI/NotificationsListItem.cpp \
    GUI/NotificationsListWidget.cpp \
    GUI/ReportHistoryWidget.cpp \
    GUI/ReportRecordWidget.cpp \
    GUI/ShowNotificationWidget.cpp \
    GUI/ShowTaskWidget.cpp \
    GUI/TaskManagementWidget.cpp \
    GUI/TaskRecordWidget.cpp \
    GUI/VacationRequestWidget.cpp \
    GUI/VacationRequestsItem.cpp \
    main.cpp \

HEADERS += \
    GUI/ActivityRecordWidget.h \
    GUI/Authorization.h \
    GUI/BusinessTripListWidget.h \
    GUI/CreateReportWidget.h \
    GUI/CreateVacationRequestWidget.h \
    GUI/MainWindow..h \
    GUI/NotificationsListItem.h \
    GUI/NotificationsListWidget.h \
    GUI/ReportHistoryWidget.h \
    GUI/ReportRecordWidget.h \
    GUI/ShowNotificationWidget.h \
    GUI/ShowTaskWidget.h \
    GUI/TaskManagementWidget.h \
    GUI/TaskRecordWidget.h \
    GUI/VacationRequestWidget.h \
    GUI/VacationRequestsItem.h

FORMS += \
    GUI/ActivityRecordWidget.ui \
    GUI/Authorization.ui \
    GUI/BusinessTripListWidget.ui \
    GUI/CreateReportWidget.ui \
    GUI/CreateVacationRequestWidget.ui \
    GUI/MainWindow.ui \
    GUI/NotificationsListItem.ui \
    GUI/NotificationsListWidget.ui \
    GUI/ReportHistoryWidget.ui \
    GUI/ReportRecordWidget.ui \
    GUI/ShowNotificationWidget.ui \
    GUI/ShowTaskWidget.ui \
    GUI/TaskManagementWidget.ui \
    GUI/TaskRecordWidget.ui \
    GUI/VacationRequestWidget.ui \
    GUI/VacationRequestsItem.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
