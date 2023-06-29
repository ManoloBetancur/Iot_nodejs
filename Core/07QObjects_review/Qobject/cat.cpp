#include "cat.h"

Cat::Cat(QObject *parent) : QObject(parent)
{

}

void Cat::scared()
{
    qInfo() << "The cat got scared, emitting run signal";
    emit run();
}
