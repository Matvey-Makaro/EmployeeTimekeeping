#pragma once

#include <QObject>

class AuthorizationUtilsTests : public QObject
{
    Q_OBJECT
public:
    explicit AuthorizationUtilsTests(QObject *parent = nullptr);

private slots:
    void IsLoginCorrectTest_data();
    void IsLoginCorrectTest();

    void IsPasswordCorrectTest_data();
    void IsPasswordCorrectTest();
};

