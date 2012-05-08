#ifndef BBIO_H_INCLUDED
#define BBIO_H_INCLUDED

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

#define HIGH   1
#define LOW    0
#define OUTPUT 1
#define INPUT  0
struct digital {
enum{
    P8_3,
    P8_4,
    P8_6,
    P8_11,
    P8_12,
    P8_14,
    P8_15,
    P8_16,
    P8_17,
    P8_18,
    P8_20,
    P8_21,
    P8_22,
    P8_23,
    P8_24,
    P8_25,
    P8_26,
    P8_27,
    P8_28,
    P8_29,
    P8_30,
    P8_39,
    P8_40,
    P8_41,
    P8_42,
    P8_43,
    P8_44,
    P8_45,
    P8_46,
    P9_12,
    P9_15,
    P9_23,
    P9_25,
    P9_27,
    P9_42
};
};
struct analog {
enum analogPin{
    P9_33,
    P9_35,
    P9_37,
    P9_38,
    P9_39,
    P9_40
};
};
const int digitalPinNum[] = {38, 39, 34, 35, 45, 44, 26, 47, 46, 27, 65, 63, 62, 37, 36,
                      33, 32, 61, 86, 88, 87, 89, 76, 77, 74, 74, 72, 73, 70, 71,
                      60, 48, 49, 117, 115, 7};

const int analogPinNum[] = {4, 6, 5, 2, 3, 0, 1};


void digitalWrite(int pin, int value);

int digitalRead(int pin);

void exportPin(int pin);

void unExport(int pin);

void digitalMode(int pin, int mode);

long pulseIn(int pin);

int analogRead(int pin);

void muxPin(int pin, int mode);

void PWMout(int pin, int frequency, int percent);

class Pin {
protected:
    int pin;
public:
    virtual void setPin(int) = 0;
    void setMode(int);
    virtual void write(int) = 0;
    virtual int  read() = 0;
    void unexport();

};

class DigitalPin : public Pin {
public:
    DigitalPin();
    DigitalPin(int, int);
    ~DigitalPin();
    void setPin(int);
    void write(int);
    int read();


};




#endif // BBIO_H_INCLUDED
