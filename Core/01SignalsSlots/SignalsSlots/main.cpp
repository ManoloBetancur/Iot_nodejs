#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include "Radio.h"
#include "Station.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //LESSON 1;

    //    Source oS;
    //    destination oD;

    //    //QObject::connect(OBJECT1, signal1, OBJECT2, signal2)
    //    //Comunication between Q Objects

    //    QObject::connect(&oS,&Source::mySignal,&oD,&destination::mySlot);
    /*########################################
 *If we connect Objects like before requires manual management of the
 *object lifetime. Below you will see how to managed the lifetime sort of
 *automatically
*/

    //    //Emiting the signal;
    //    oS.test();

    //LESSON 2;

    radio radio_colombia;
    //Array of pointers that points to stations QObjects
    station *channels[3];

    //Stations on the heap memory
    channels[0] = new station(&radio_colombia,104,"La mega 104.9MHz");
    channels[1] = new station(&radio_colombia,93,"RCN radio 93.9 MHz");
    channels[2] = new station(&radio_colombia,92,"Caracol radio 92.5MHz");
    //Because we are setting the QObjetct station to a radio parent address,
    //When we delete radio, the memory allocated in station will be delated to.

    radio_colombia.connect(&radio_colombia,&radio::quit,&a,&QCoreApplication::quit,Qt::QueuedConnection);
    /*########################################
 *If we connect Objects like this, it
 *leverages the QObject framework to handle object ownership
 *and automatically disconnects connections when necessary.
*/

    //    for(int i = 0; i<3; i++)
    //    {
    //        station *channel = channels[i];
    //        radio_colombia.connect(channel,&station::send,&radio_colombia,&radio::listen);
    //    }
    do
    {
        qInfo() << "Enter on, off, test or quit";
        QTextStream qtin(stdin);
        qtin.skipWhiteSpace();
        QString line = qtin.readLine().trimmed().toUpper();

        //DISCONNECTING ALL THE radio objects to all the stations
        if(line == "OFF")
        {
            qInfo() << "TURNING OFF";
            for(int i = 0; i<3; i++)
            {
                station *channel = channels[i];
                radio_colombia.disconnect(channel,&station::send,&radio_colombia,&radio::listen);
            }
            qInfo() << "RADIO is OFF";
        }

        //CONNECTING ALL THE radio objects to all the stations
        if(line == "ON")
        {
            qInfo() << "TURNING ON";
            for(int i = 0; i<3; i++)
            {
                station *channel = channels[i];
                radio_colombia.connect(channel,&station::send,&radio_colombia,&radio::listen);
            }
            qInfo() << "RADIO is ON";
        }

        //EMITS THE SIGNALS of bradcast
        if(line == "TEST")
        {
            qInfo() << "TESTING";
            for(int i = 0; i<3; i++)
            {
                station *channel = channels[i];
                channel->broadcast("Broadcasting the channel");
            }
            qInfo() << "RADIO tested";
        }

        if(line == "QUIT")
        {
            qInfo() << "QUITING ...";
            emit radio_colombia.quit();
            break;
        }

    }while(true);



    return a.exec();
}
