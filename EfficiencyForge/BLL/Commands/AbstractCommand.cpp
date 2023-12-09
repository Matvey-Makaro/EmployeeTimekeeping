#include "AbstractCommand.h"


void AbstractCommand::WriteLog(ILogger& l)
{
    for(const auto& c : _logger.GetCriticals())
        l.WriteCritical(c.fromFlag, c.codeFlag, c.what);
    for(const auto& w : _logger.GetWarnings())
        l.WriteWarning(w.fromFlag, w.codeFlag, w.what);
    for(const auto& t : _logger.GetTraces())
        l.WriteTrace(t);
}
