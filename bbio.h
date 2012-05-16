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



void digitalWrite(char *pin, int value);

int digitalRead(char *pin);

void exportPin(char* pin);

void unExport(char* pin);

void digitalMode(char* pin, int mode);

long pulseIn(char* pin, int value);

int analogRead(char* pin);

void muxPin(char* pin, int mode);

void PWMout(char* pin, int frequency, int percent);

void pinDemo();



#endif // BBIO_H_INCLUDED
