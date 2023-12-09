#include <QApplication>
#include "GUI/MainWindow.h"
#include "App/AppConfigBuilder.h"
#include "App/AppConfig.h"
#include "App/AppConfigurator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AppConfigBuilder cfgBuilder;
    auto cfg = cfgBuilder.Build();
    AppConfigurator appConfigurator(cfg);
    appConfigurator.Run();

//    MainWindow w;
//    w.show();
    return a.exec();
}
