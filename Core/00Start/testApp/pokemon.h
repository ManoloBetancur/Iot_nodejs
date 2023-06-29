#ifndef POKEMON_H
#define POKEMON_H

#include <QObject>
#include <QDebug>

class pokemon : public QObject
{
    Q_OBJECT
public:
    //Constructor
    explicit pokemon(QObject *parent = nullptr, QString name = "Unamed", QString type = "Unkown",
                     int health = 55);

    //Desctrucor
    ~pokemon();

    //atributes
    QString name;
    QString type;
    int health;

    //Methods
    void seeName();
    void seeType();
    void seeHealth();
signals:

};

#endif // POKEMON_H
