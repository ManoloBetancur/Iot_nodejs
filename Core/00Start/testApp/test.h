#ifndef TEST_H
#define TEST_H

#include <QObject>
#include<QDebug>
#include "pokemon.h"

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);
    ~test();

    pokemon *pok;

signals:

};

#endif // TEST_H
