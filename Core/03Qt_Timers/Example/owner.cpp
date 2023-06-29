#include "owner.h"


Owner::Owner(QObject *parent) : QObject(parent)
{

}

void Owner::giveSnacks()
{
    qInfo() << "Emitting treats (Snacks are ready)";
    emit treats();
}
