/*
    What
    Dog owner

    Why
    Show that we can easily goof up

    How
    See below
*/

//See conection types

#include <QCoreApplication>
#include "owner.h"
#include "dog.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Owner owner;
    Dog dog;

    //Auto connection
    QObject::connect(&owner,&Owner::treats,&dog,&Dog::treats); //Auto


    for(int i = 0; i < 10; i++)
    {
        // Unique connecton avoids multiple connection
        QObject::connect(&owner,&Owner::treats,&dog,&Dog::treats,Qt::UniqueConnection); //Auto
    }

    /*
     *Even though we call connect multiple
     *times, it only execute one time
     */

    owner.giveSnacks();

    return a.exec();
}
