#include <QTest>
#include <QString>
#include "Utils/AuthorizationUtils.h"
#include "AuthorizationUtilsTests.h"

AuthorizationUtilsTests::AuthorizationUtilsTests(QObject *parent) : QObject(parent)
{}

void AuthorizationUtilsTests::IsLoginCorrectTest_data()
{
    QTest::addColumn<QString>("login");
    QTest::addColumn<bool>("expectedResult");

    QTest::newRow("test1") << "normal_login-123" << true;
    QTest::newRow("test2") << "IncorrectLogin" << true;
    QTest::newRow("test3") << "inc*rrect_l*gin" << false;

}

void AuthorizationUtilsTests::IsLoginCorrectTest()
{
    QFETCH(QString, login);
    QFETCH(bool, expectedResult);

    bool isCorrect = IsLoginCorrect(login);
    QVERIFY(isCorrect == expectedResult);
}

void AuthorizationUtilsTests::IsPasswordCorrectTest_data()
{
    // TODO: Impl
}

void AuthorizationUtilsTests::IsPasswordCorrectTest()
{
    // TODO: Impl
}
