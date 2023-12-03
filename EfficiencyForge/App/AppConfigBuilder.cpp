#include "AppConfigBuilder.h"



AppConfigShp AppConfigBuilder::Build() const
{
    auto cfg = AppConfigShp::create();
    FillDBSettings(cfg.get());
    return cfg;
}

void AppConfigBuilder::FillDBSettings(AppConfig* cfg) const
{
    auto& dbSettings = cfg->DbSettings;
    dbSettings.Name = "EfficiencyForge";
    dbSettings.UserName = "root";
    dbSettings.HostName = "localhost";
    dbSettings.Password = "admin";
    dbSettings.Port = 3306;
}
