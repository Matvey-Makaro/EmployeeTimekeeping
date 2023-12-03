#pragma once

#include "AppConfig.h"

class AppConfigBuilder
{
public:
    AppConfigBuilder() = default;

    AppConfigShp Build() const;

private:
    void FillDBSettings(AppConfig* cfg) const;

};

