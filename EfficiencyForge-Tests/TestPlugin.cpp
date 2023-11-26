#include "TestsRunner.h"
#include "SimpleTest.h"
#include "TestPlugin.h"


TestPlugin::TestPlugin(QString outputPath, QString specificFormat) :
    _outputPath(std::move(outputPath)),
    _specificFormat(std::move(specificFormat))
{}

void TestPlugin::Run() const
{
    TestsRunner runner(_outputPath, _specificFormat);
    runner.RunTest<SimpleTest>();
}
