#ifndef KELVINARTOPORT_H
#define KELVINARTOPORT_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "outdisplay.h"

class KelvinArtoPort : public QObject
{
Q_OBJECT

public:
    explicit KelvinArtoPort(QObject *parent = 0);
public:
    float getTemp(){return temp;}
    float getEmiss(){return emiss;}
    void setTemp(float tempEx){temp = tempEx;}
    void setEmiss(float emissEx){emiss = emissEx;}
    QSerialPort serialPort;
signals:
    void finished();
    void portReading();
public slots:
        void initOut();
        void outputData();
private:
        OutDisplay outDisp;
        //QByteArray  readData;
        QString str_temp;
        QString str_emiss;
        float temp=0;
        float emiss=0;
        QTimer *timer;

};

#endif // KELVINARTOPORT_H
