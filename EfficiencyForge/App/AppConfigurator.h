#pragma once


#include <QSharedPointer>

class AppConfigurator
{
public:
    AppConfigurator() = default;

    void Run();

private:
    void Authorization();
    void MainWork();

};

using AppConfiguratorShp = QSharedPointer<AppConfigurator>;
