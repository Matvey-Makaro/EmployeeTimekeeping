#pragma once

#include <QObject>

class SimpleTest : public QObject
{
    Q_OBJECT
public:
    explicit SimpleTest(QObject *parent = nullptr);
    virtual ~SimpleTest();

private slots:
    void test1() const;
    void test2() const;
};

