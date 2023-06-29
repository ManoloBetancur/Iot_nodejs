#include <QCoreApplication>
#include <QDebug>
#include <QDate>
#include <QDateTime>
#include <QVariant>
#include "pet.h"

void test(QVariant value) //Copy
{
    qInfo() << value;

    int i = 0;
    bool ok = false;
    i = value.toInt(&ok);
    if(ok)
    {
        qInfo() << "INT" << i;
    }
    else
    {
        qInfo() << "Not a int!";
    }
}



//typedef helps usingdata types and classes with custom names,
//This helps make things more readable;
typedef QMap<QString,Pet*> petList;

petList createPets(int max)
{
    petList map;
    for(int i = 0; i < max; i++)
    {
        QString id = QString::number(i);
        Pet* pet = new Pet(); //notice the possible memory leak!
        pet->setAge(i * 3);
        pet->setName("Pet: " + id);
        map.insert(id,pet);
    }

    return map; //Notice the copy!
}


void listPets(petList pets) //Notice the copy
{
    foreach(QString key, pets.keys())
    {
        Pet* pet = pets.value(key);
        qInfo() << key << pet->name() << " is Age: " << pet->age();
    }
}

int main(int argc, char *argv[])
{
    qInfo()<< "_________QDate time section_______";

    QCoreApplication a(argc, argv);

    QDate today = QDate::currentDate();
    qInfo() << today;
    qInfo() << today.addDays(1);
    qInfo() << today.addYears(20);

    qInfo()<<"ISO Date format : "<<today.toString(Qt::DateFormat::ISODate);
    qInfo()<<"RFC Date format : "<< today.toString(Qt::DateFormat::RFC2822Date);
    qInfo()<<"Text date : "<< today.toString(Qt::DateFormat::TextDate);

    QTime now = QTime::currentTime();
    qInfo()<<"ISO Date format : "<<now.toString(Qt::DateFormat::ISODate);
    qInfo()<<"RFC Date format : "<< now.toString(Qt::DateFormat::RFC2822Date);
    qInfo()<<"Text date : "<< now.toString(Qt::DateFormat::TextDate);

    QDateTime current = QDateTime::currentDateTime();
    qInfo() << current;
    QDateTime expire = current.addDays(45);
    qInfo() << "This expires on: "<< expire;

    if(current > expire)
    {
        qInfo() << "This hasn't expired yet";
    }
    else
    {
        qInfo() << "The current date is not greater than expire Date";
    }
    //QString
    qInfo()<< "_________QString section_______";
    QString name = "   Manolo";
    qInfo() << name;
    qInfo() << name.mid(0,3); //String slicing
    qInfo() << name.trimmed().insert(0,"Ingeneer. ");
    qInfo() << name.split(" ");

    int found_index = name.indexOf(".");
    if(found_index != -1) qInfo()<<"Element found";

    QString last_mame = "Betancur";
    QString full_name = name.trimmed() + " " + last_mame;
    qInfo() << full_name;

    /* #########QByteArray####*/
    qInfo()<< "_________QByte Array section_______";
    QString msg = "Hello QT";
    QByteArray buffer(msg.toUtf8());
    buffer.append("!");
    qInfo()<<buffer;
    qInfo() << buffer.rightJustified(10,'\\');
    qInfo() << buffer.at(buffer.length()-1); //Last Character

    QString fromBufferString(buffer);
    qInfo()<<fromBufferString;
    //Encoding

    qInfo() << buffer.toBase64();
    qInfo() << buffer.toHex();


    /* #########QVariant####*/
    qInfo()<< "_________QByte Array section_______";

    QVariant value  = 1;
    QVariant value2 = "Hello World";

    test(value);
    test(value2);

    qInfo()<< "_________QString List section_______";

    QString data = "Hello world how are you";
    QStringList lst = data.split(" "); //split method returns a QStringList
    qInfo() << lst;

    foreach(QString str,lst)
    {
        qInfo() << str;
    }

    lst.sort(Qt::CaseInsensitive);
    qInfo() << lst;

    QString myvar = "Hello";
    if(lst.contains(myvar))
    {
        int index = lst.indexOf(myvar);
        qInfo() << lst.value(index);
    }

    /* #########QList####*/

    qInfo()<< "_________QList section_______";
    QString str = "Hello world how are you";
    QList<QString> list = str.split(" ");

    foreach(QString word, list)
    {
        qInfo() << word;
    }

    QList<int> age({44,56,21,13});
    age.append(99);
    age.remove(1);
    qInfo() << age;

    foreach(int word, age)
    {
        qInfo() << word;
    }
    /* #########QVector####*/
    qInfo()<< "_________QVector Section_______";

    QString text = "Hello world how are you";
    QVector<QString> vector = text.split(" ");

    foreach(QString word, vector) {
        qInfo() << word;
    }

    QVector<int> ages({44,56,21,13});
    foreach(int age, ages) {
        qInfo() << age;
    }

    /* #########QMap####*/
    qInfo()<< "_________QMap Section_______";
    //This is like python dictionaries or json format

    petList pets = createPets(5);
    qInfo() << "Count:" << pets.count();
    listPets(pets);

    //    Pet* pet = new Pet(); //notice the possible memory leak!
    //    pet->setAge(99);
    //    pet->setName("BadKitty");
    //    pets.insert("1",pet);

    qDeleteAll(pets.values());
    pets.clear();

    qInfo() << "Count:" << pets.count();
    listPets(pets);




    return a.exec();
}
