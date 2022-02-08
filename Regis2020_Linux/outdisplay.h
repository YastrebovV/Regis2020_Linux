#ifndef OUTDISPLAY_H
#define OUTDISPLAY_H

#include <wiringPi.h>
#include <QThread>

//#define A 0
//#define B 1
//#define C 2
//#define D 3
//#define E 4
//#define F 5
//#define G 6

#define DS 0
#define SHCP 1
#define STCP 2

#define D1 21
#define D2 22
#define D3 27
#define D4 25


class OutDisplay
{
public:
    OutDisplay();
    void digitOutput(int digit);
    void initOutput();
    void clearDisplay();
    void segmentSelect(int numSegment);
    void pulse(int pin);
    void shiftOut(unsigned char byte);
private:
    unsigned char numbers[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
};

class Sleep : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};

#endif // OUTDISPLAY_H
