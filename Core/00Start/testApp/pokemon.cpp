#include "pokemon.h"
#include <QDebug>

pokemon::pokemon(QObject *parent, QString name, QString type, int health)
{
    qInfo()<<this<<"Pokemon created";
    this->name = name;
    this->type = type;
    this->health = health;
}

pokemon::~pokemon()
{
    qInfo()<<this << "Pokemon deleted";
}

void pokemon::seeName()
{
    qInfo()<<this->name;
}

void pokemon::seeType()
{
    qInfo()<<this->type;
}

void pokemon::seeHealth()
{
    qInfo()<<this->health;
}
