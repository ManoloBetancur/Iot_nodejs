#include "test.h"

test::test(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "Test object created";
}

test::~test()
{
    qInfo()<<this<< "Test object destroyed";

}
