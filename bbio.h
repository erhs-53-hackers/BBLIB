#ifndef BBIO_H_INCLUDED
#define BBIO_H_INCLUDED

#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

//#include <string.h>



#define HIGH   1
#define LOW    0
#define OUTPUT 1
#define INPUT  0



void digitalWrite(const char *pin, int value);

int digitalRead(const char *pin);

void exportPin(const char* pin);

void unExport(const char* pin);

void digitalMode(const char* pin, int mode);

long pulseIn(const char* pin, int value);

int analogRead(const char* pin);

void muxPin(const char* pin, int mode);

void PWMout(const char* pin, int frequency, int percent);

void pinDemo();



#endif // BBIO_H_INCLUDED
