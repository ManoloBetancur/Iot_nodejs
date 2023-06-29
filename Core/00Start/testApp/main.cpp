#include <QCoreApplication>
#include <QDebug>
#include "pokemon.h"
#include "test.h"

//void create_pok()
//{
//    pokemon pok(nullptr,"Pikachu","Electric",100);

//    //Pokemon will be destroyed at the end of the function
//}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    create_pok();

//    pokemon pok1(nullptr,"Pikachu","Electric",100);
//    pok1.seeName();
//    pok1 .seeType();
//    pok1.seeHealth();

//    pok1.name = "Liko";
//    pok1.seeName();

    /*PARENT CHILD RELATIONSHIP*/

    //Creates a pointer that points to the class test, that will be a parent pointer
    test *parent = new test(&a); //object initialize with the pointer of the core app "a"

    parent->pok = new pokemon(parent,"Pikachu","Electric",100);
    //Instance of the obj where creaated in test class but initialize where with parent pointer.

    delete parent;//If we forget to do this, when a.exec() occur, the pok obj will be destroyed because
    //Because is a child of "a"

    return a.exec();
}
