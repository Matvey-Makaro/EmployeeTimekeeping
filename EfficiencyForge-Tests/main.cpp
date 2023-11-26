#include <QDir>
#include "TestPlugin.h"

int main()
{

    QString curDir = QDir::currentPath();
    QString format = "-txt";
    TestPlugin plugin(curDir, format);
    plugin.Run();

    return 0;
}
