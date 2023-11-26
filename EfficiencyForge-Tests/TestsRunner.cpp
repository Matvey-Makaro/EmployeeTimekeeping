#include <QDebug>
#include "TestsRunner.h"


TestsRunner::TestsRunner(QString outputPath, QString specificFormat) :
    _outputPath(std::move(outputPath)),
    _specificFormat(std::move(specificFormat))
{}

QStringList TestsRunner::CreateArgs(const QString &className)
{
    QStringList args;
    args << className << _specificFormat;

    //    args << className << "-o" << _outputPath + "/testout.txt" << _specificFormat;

    return args;
}
