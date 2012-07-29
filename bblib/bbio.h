#ifndef BBIO_H_INCLUDED
#define BBIO_H_INCLUDED

#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <time.h>

//#include <string.h>



#define HIGH   1
#define LOW    0
#define OUTPUT 1
#define INPUT  0



void digitalWrite(const char *pin, int value);

void fastDigitalWrite(const char *pin, int value);

int digitalRead(const char *pin);

int fastDigitalRead(const char *pin);

void exportGpio(const char* pin);

void unexportGpio(const char* pin);

void digitalMode(const char* pin, int mode);

void fastDigitalMode(const char* pin, int mode);

long pulseIn(const char* pin, int value, double timeout);

long fastPulseIn(const char* pin, int value);

int analogRead(const char* pin);

void muxPin(const char* pin, int mode);

void pwmWrite(const char* pin, int frequency, int percent, int isrun);

void pinDemo();



#endif // BBIO_H_INCLUDED
