#include "kelvinartoport.h"

KelvinArtoPort::KelvinArtoPort(QObject *parent) :
    QObject(parent)
{

}

void KelvinArtoPort::initOut()
{
    outDisp.initOutput();
    //outDisp.digitOutput(0);
}

void KelvinArtoPort::outputData()
{
    initOut();
    while (1) {
        outDisp.digitOutput(temp);
      //  outDisp.digitOutput(2222);
      //  Sleep::usleep(1);
    }
}

