#include "Serial.hpp"
#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include "PWM.hpp"
#include "Driveable.hpp"
#include "DigitalPin.hpp"
#include "bbdrive.hpp"


extern "C" {
#include <bbio.h>
//#include <gperf_pinMap.h>
}
using namespace std;

long microsecondsToInches(long microseconds) {
    // According to Parallax's datasheet for the PING))), there are
    // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
    // second).  This gives the distance travelled by the ping, outbound
    // and return, so we divide by 2 to get the distance of the obstacle.
    // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
    return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
    // The speed of sound is 340 m/s or 29 microseconds per centimeter.
    // The ping travels out and back, so to find the distance of the
    // object we take half of the distance travelled.
    return microseconds / 29 / 2;
}

bool isDebugMode() {
    //true  : debug
    //false : run
    const char *pin = "P8_3";
    DigitalPin gate(pin);
    bool value = gate.get();
    return value;
}

int main() {

    long duration, inches, cm;

    const char* pingPin = "P9_15";
    exportGpio(pingPin);

    int pin = 48;
    char fastPin[29];
    snprintf(fastPin, sizeof(fastPin), "/sys/class/gpio/gpio%i/value", pin);


    while(true) {
        digitalMode(pingPin, OUTPUT);
        digitalWrite(pingPin, LOW);
        usleep(2);
        digitalWrite(pingPin, HIGH);
        usleep(5);
        digitalWrite(pingPin, LOW);


        digitalMode(pingPin, INPUT);
        duration = pulseIn(pingPin, HIGH, 0.4);



        inches = microsecondsToInches(duration);
        cm = microsecondsToCentimeters(duration);

        cout << "cm = " << cm << ", duration = " << duration <<endl;
        usleep(3000);
    }







    return 0;
}
