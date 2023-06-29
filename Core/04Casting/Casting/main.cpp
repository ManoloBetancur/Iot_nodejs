/*
    What
    Dynamic cast

    Why
    Casting is complex, we want to make it easier

    The dynamic_cast operator ensures that if you convert a pointer
    to class A to a pointer to class B,
    the object of type A pointed to by the former belongs to an object
    of type B or a class derived from B as a base class subobject.

    How
    https://en.cppreference.com/w/cpp/language/dynamic_cast
*/

#include <QCoreApplication>
#include <QDebug>
#include "car.h"
#include "racecar.h"
#include "feline.h"


//Dynamic cast

//dynamic_cast can be used only with pointers and references to objects.
//Its purpose is to ensure that the result of the type conversion is a valid complete object of the requested class.

void testDrive(Car* obj)
{
    obj->drive();
    obj->stop();
}

void race(RaceCar* obj)
{
    obj->drive();
    obj->stop();
    obj->gofast();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    double value = 3.1415;
    qInfo() << "Double: " << value;

    //The compiler takes the decision of converting the value
    int age = value;
    qInfo() << "Age: " << age; //Implicit conversion should not be trusted

    //We defined exactly how the value is converted
    age = (int)value; //We control this conversion
    qInfo() << "Age: " << age; //Explicit conversion should be trusted

    /*Dynamic casting*/

    //ONLY TO POINTERS

    RaceCar* player1 = new RaceCar(&a);
    testDrive(player1); //Implicit conversion


    //Correct way
    Car* obj = dynamic_cast<Car*>(player1); //Explicitly convert
    if(obj) testDrive(obj);

    Feline* cat = new Feline(&a);
    Car* catcar = dynamic_cast<Car*>(cat);
    qInfo() << "CatCar" << catcar;
    if(catcar) testDrive(catcar);

    /*Static casting*/
    //Helps to cast a base class pointer inot a derived or child class pointer
    //So if initially I have variable pointing to a base class, the static casting,
    // Tries to convert the variable type is being point to, to a pointer of a derived class
    // So, without chaging the orignal addr, with static casting, it casts to a diferent pointer type.

    //BASE CLAS CAR

    //Creating a car in the heap memory, and passing the memory managment to QT,
    //Using "&a" to set the QOBJET to have the application as the parent.
    //So everytime the application closes it frees the memory.
    Car *car = new Car(&a);
    qInfo()<<car;//See if the car obj was created and see its memoery addr

    //Static cast to convert a car objt into its child class racecar
    qInfo()<< "Racing a car that was converted";
    race((RaceCar*)car);// It works but is not recommended, it could be confusing

    qInfo()<< "Racing a car that was converted, in a better way";
    RaceCar *meteoro = static_cast<RaceCar*>(car);
    //Checks if the obj is not 0, if it is, the conversion wasn't succesful
    if(meteoro) race(meteoro);

    qInfo() << "Its a different obj but the addr did not changed";
    qInfo()<< meteoro;



    /*Reinterpret cast*/
/*
 * Is a type of cast operator that allows you to reinterpret
 * the meaning of a pointer or value of one type as a pointer or value of a different type.
 * It is a powerful and potentially dangerous feature
 * , as it bypasses the usual type safety mechanisms of the language.
 *
 *  Unlike static_cast, but like const_cast, the reinterpret_cast expression does not
    compile to any CPU instructions

    (except when converting between integers and pointers or on obscure
    architectures where pointer representation depends on its type).

    It is purely a compile-time directive which instructs the compiler
    to treat the expression as if it had the a new type.

    Remember:
    The implicit cast is C++ doing it for us
    The explicit cast is us telling C++ what to do
    The static_cast operator performs a nonpolymorphic cast.
    The dynamic_cast operator ensures inheritence is good
    The reinterpret_cast operator types to convert it to a different type
*/

    //Racecar creation
    RaceCar *herby = new RaceCar(&a); //memory delegated to QT app

    //Converthe type (Cast) of RaceCar to Car.
    //"Desenchanting herby into a normal volkswagen
    Car *volkswagen = dynamic_cast<Car *>(herby);\
    //if the conversion succeed, perform a test drive into the new obj
    qInfo()<<"Testing";
    if(volkswagen) testDrive(volkswagen);

    //static Cast
    RaceCar *speedy =static_cast<RaceCar*>(volkswagen);
    qInfo()<<"Testing, the new object";
    if(speedy) race(speedy);

    //REINTERPRET
    //Try to convert a RaceCar into a int ...
    qInfo() << "Original RaceCar pointer :"<< speedy;
    int *ptr = reinterpret_cast<int*>(speedy);
    qInfo() << "Integer pointer from RaceCar :"<< ptr;

    qInfo()<<"Trying to converted back to RaceCar";
    RaceCar *speedy2 = reinterpret_cast<RaceCar*>(ptr);
    qInfo()<<"Let's race it";
    if(speedy2) race(speedy2);
    qInfo()<<"Let's see its color";
    qInfo()<<speedy2->color;

    qInfo() <<"Now let's try to convert the integer pointer into a cat";
    Feline *cat_new = reinterpret_cast<Feline*>(ptr);
    qInfo()<< "Is the new object a reall cat ?";
    cat_new->hiss();
    qInfo() << "Is hissing, so it is a cat, we converted a int into a cat";

    //This overall is a bad a idea because all the information stored in the
    //previous obj are now gone.

    /*QObject casting*/

    //QT has his its own way to cast between QObjects

    //From derived class to a base class
    RaceCar *mercedes = new RaceCar(&a);
    //Casting with Qt
    Car *renault = qobject_cast<Car *>(mercedes);
    qInfo() << "From derived class to a base class";
    renault->drive();

    //Base class to the derived class
    qInfo() <<"\nFrom base class to the derived class";
    RaceCar *ferrari = qobject_cast<RaceCar*>(renault);
    ferrari->gofast();

    return a.exec();
}
