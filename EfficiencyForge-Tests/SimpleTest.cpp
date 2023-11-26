#include <QTest>
#include "SimpleTest.h"

SimpleTest::SimpleTest(QObject *parent) : QObject(parent)
{}

SimpleTest::~SimpleTest()
{

}

void SimpleTest::test1() const
{
    QVERIFY(1 == 1);
}

void SimpleTest::test2() const
{
    QVERIFY(2 == 2);
}
