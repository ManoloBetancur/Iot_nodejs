#include "destination.h"

destination::destination(QObject *parent)
    : QObject{parent}
{

}

void destination::mySlot(QString message)
{

    qInfo()<<message;
}
