#include "Radio.h"

radio::radio(QObject *parent)
    : QObject{parent}
{

}

void radio::listen(int chan, QString name, QString msg)
{
    qInfo() << "Channel : "<< chan<< " Name: "<< name<< " Message: "<<msg;

}
