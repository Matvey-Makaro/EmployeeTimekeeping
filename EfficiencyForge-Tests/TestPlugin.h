#pragma once

#include <QString>

class TestPlugin
{
public:
    TestPlugin(QString outputPath, QString specificFormat);

    void Run() const;

private:
    QString _outputPath;
    QString _specificFormat;
};

