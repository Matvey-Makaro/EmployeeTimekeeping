#pragma once

#include <QSharedPointer>
#include "DAL/DBSettings.h"

struct AppConfig
{
    DBSettings DbSettings;

};
using AppConfigShp = QSharedPointer<AppConfig>;
