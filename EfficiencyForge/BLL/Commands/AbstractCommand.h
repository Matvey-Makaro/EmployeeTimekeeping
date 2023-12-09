#pragma once

#include "Utils/Loggers/AccumulateLogger.h"
#include "ICommand.h"

class AbstractCommand : public ICommand
{
public:
    AbstractCommand() = default;

    void WriteLog(ILogger&) override;

protected:
    AccumulateLogger _logger;
};

