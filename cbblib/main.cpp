#include "Serial.hpp"
#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include "PWM.hpp"
#include "DigitalPin.hpp"


extern "C" {
#include <bbio.h>
}
using namespace std;

#define BAUDRATE 19200
#define PORT "/dev/ttyO2"
#define MUX_MODE 1



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
    //exportGpio("P8_11");
    //printf("yo:%#x\n\n\n", 39);
    cout << "yo"<<endl;
    muxPin("P9_21", 1);
    Serial serial(PORT, B19200);

    serial.writeString("Hello world\n");
    serial.writeString("HOW IS YOU BE DOINZZZZZZZ!\n");





    return 0;
}
