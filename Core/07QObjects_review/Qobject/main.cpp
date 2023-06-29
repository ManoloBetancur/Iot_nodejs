/*
    What
    QObject

    Why
    Base class for everything Qt (non-template)
    We have talked about this a LOT

    How
    See below
    review Signals, Slots, MOC, macros
*/

#include <QCoreApplication>
#include <QDebug>
#include "dog.h"
#include "cat.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Cat cat;
    cat.setObjectName("fifi");

    Dog dog;
    dog.setObjectName("Doky");

    //dog.chase(); //Zero for sender as nothing was emitted
    //Conect the dog signal to the cat slot
    QObject::connect(&dog,&Dog::bark,&cat,&Cat::scared);
    //Connect the cat signal to the dog slot
    QObject::connect(&cat,&Cat::run,&dog,&Dog::chase);

    emit dog.bark();

    return a.exec();
}
