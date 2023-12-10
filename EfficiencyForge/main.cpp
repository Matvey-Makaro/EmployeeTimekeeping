#include <QApplication>
#include "App/AppConfigBuilder.h"
#include "App/AppConfig.h"
#include "App/AppConfigurator.h"

#include "TestModule/CountryFlag.h"
#include "TestModule/CountryWidget.h"
#include "TestModule/TableViewModel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AppConfigBuilder cfgBuilder;
    auto cfg = cfgBuilder.Build();
    AppConfigurator appConfigurator(cfg);
    appConfigurator.Run();

//    auto values = new QList<CountryFlag>;
//    values->append(CountryFlag(1," Russia", "russia.png"));
//    values->append(CountryFlag(11, "Belarus", "belarus.png"));
//    values->append(CountryFlag(22, "Slovakia", "slovakia.png"));
//    values->append(CountryFlag(33, "Slovenia", "slovenia.png"));
//    values->append(CountryFlag(44, "China", "china.png"));
//    values->append(CountryFlag(55, "Mongolia","mongolia.png"));

//    auto model = new TableViewModel();
//    model->populate(values);

//    auto countryWidget = new CountryWidget();
//    countryWidget->GetTableView()->setModel(model);
//    countryWidget->show();

    return a.exec();
}
