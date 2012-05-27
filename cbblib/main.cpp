#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include "PWM.hpp"
#include "DigitalPin.hpp"

extern "C" {
#include <bbio.h>
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

    //gate.set(1);

    bool value = gate.get();

    /*
    exportGpio(pin);
    muxPin(pin, 0x27);

    bool value = digitalRead(pin);

    cout << digitalRead(pin) << ";" << value;

    unexportGpio(pin);
    */

    return value;
}

int main() {
    //exportGpio("P8_11");
    //printf("yo:%#x\n\n\n", 39);
    if(isDebugMode()) {
        cout << "DEBUG MODE" <<endl;
        return 0;
    }
    cout << "RUN MODE" << endl;
    /*

    DigitalPin led("P8_4");

    for(int i=0;i<10;i++) {
        led.set(1);
        sleep(1);
        led.set(0);
        sleep(1);
    }
    */



    const char *ping = "P8_3";
    exportGpio(ping);

    while(1) {
        digitalMode(ping, OUTPUT);
        digitalWrite(ping, LOW);
        //usleep(20);
        digitalWrite(ping, HIGH);
        //usleep(50);
        digitalWrite(ping, LOW);

        digitalMode(ping, INPUT);

        long time = pulseIn(ping, HIGH);

        cout <<"Time: "<<time<<", "<<microsecondsToCentimeters(time)<<" cm"<<endl;
        usleep(100000);
    }



    return 0;
}
