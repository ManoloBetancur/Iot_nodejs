#ifndef STATION_H
#define STATION_H

#include <QObject>
#include <QDebug>


class station : public QObject
{
    Q_OBJECT
public:
    explicit station(QObject *parent = nullptr, int channel = 0, QString name = "NONE");
    QString name;
    int channel;

signals:
    void send(int chan, QString name,QString msg);

public slots:
    //This will emit the signal
    void broadcast(QString msg);

};

#endif // STATION_H
