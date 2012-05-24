#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include "PWM.hpp"
#include "DigitalPin.hpp"

extern "C" {
    #include <bbio.h>
}
using namespace std;

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
    if(isDebugMode()){
        cout << "DEBUG MODE" <<endl;
        return 0;
    }
    cout << "RUN MODE" << endl;

    DigitalPin led("P8_4");

    for(int i=0;i<10;i++) {
        led.set(1);
        sleep(1);
        led.set(0);
        sleep(1);
    }


    /*
    const char *ping = "P8_3";
    exportGpio(ping);

    while(1){
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
        */


    return 0;
}
