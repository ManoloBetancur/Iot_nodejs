#include <QCoreApplication>
#include "test.h"
#include "watcher.h"
#include <QVariant>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test tester;
    Watcher destination;

    QObject::connect(&tester, &Test::msgChanged,&destination,&Watcher::msgChanged);

    //IMPORTANT THAT THE FIRST STRING MUST MATCH THE NAME OF THE PROPERTY
    //THE NAME WAS SET IT IN Q_PROPERTY DECLARATION
    tester.setProperty("property_name",QVariant("HELLO"));

    tester.setMsg("Test msg");


    return a.exec();
}
