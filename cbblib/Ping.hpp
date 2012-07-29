#pragma once
#include <pthread.h>
#include "DigitalPin.hpp"
extern "C" {
#include <bbio.h>
}

class Ping {
private:
    const char* pin;
    double timeout;
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

    long pulse() {
        digitalMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
        usleep(2);
        digitalWrite(pin, HIGH);
        usleep(5);
        digitalWrite(pin, LOW);


        digitalMode(pin, INPUT);

        return pulseIn(pin, HIGH, timeout);;
    }

public:
    Ping(const char* pin) {
        this->pin = pin;
        exportGpio(pin);
        this->timeout = 0.4;
    }

    Ping(const char* pin, double timeout) {
        this->pin = pin;
        exportGpio(pin);

        this->timeout = timeout;
    }

    long getCm() {
        return microsecondsToCentimeters(pulse());
    }

    long getInches() {
        return microsecondsToInches(pulse());
    }

};
