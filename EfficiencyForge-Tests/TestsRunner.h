#pragma once

#include <QString>
#include <QStringList>
#include <QTest>
#include <QObject>

class TestsRunner
{
public:
//    TestsRunner() = default;
    TestsRunner(QString outputPath, QString specificFormat);

    template<typename T>
    void RunTest()
    {
        T testInstance;
        QTest::qExec(&testInstance, CreateArgs(testInstance.metaObject()->className()));
    }

private:
    QStringList CreateArgs(const QString& className);

private:
    QString _outputPath;
    QString _specificFormat;
};

