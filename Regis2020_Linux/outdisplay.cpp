#include "outdisplay.h"

OutDisplay::OutDisplay()
{

}
void OutDisplay::initOutput()
{
    //*******
    //DISPLAY PINS
//    pinMode(A, OUTPUT);
//    pinMode(B, OUTPUT);
//    pinMode(C, OUTPUT);
//    pinMode(D, OUTPUT);
//    pinMode(E, OUTPUT);
//    pinMode(F, OUTPUT);
//    pinMode(G, OUTPUT);
    pinMode(DS, OUTPUT);
    pinMode(SHCP, OUTPUT);
    pinMode(STCP, OUTPUT);

    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
    //********
}
void OutDisplay::segmentSelect(int numSegment)
{
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);

 switch(numSegment){
     case 0: digitalWrite(D1, LOW); break;
     case 1: digitalWrite(D2, LOW); break;
     case 2: digitalWrite(D3, LOW); break;
     case 3: digitalWrite(D4, LOW); break;
 }
}
void OutDisplay::clearDisplay()
{
    shiftOut(numbers[0]);
}


void OutDisplay::pulse(int pin)
{
    digitalWrite(pin, 0);
    Sleep::usleep(1);
    digitalWrite(pin, 1);
}
void OutDisplay::shiftOut(unsigned char byte)
{
    for (int i=0;i<8;i++) {
        digitalWrite(DS, ((byte & (0x80 >> i)) > 0));
        pulse(SHCP);
    }
    pulse(STCP);
}

void OutDisplay::digitOutput(int digit)
{
   int selectedSegment = 3;

   do{
       //clearDisplay();
       shiftOut(numbers[digit%10]);
       segmentSelect(selectedSegment);
       digit = digit/10;
       selectedSegment--;
   }while(digit);
}
