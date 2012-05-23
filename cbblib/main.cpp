#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include "bbdrive.hpp"
extern "C" {
#include <bbio.h>
}
using namespace std;

int main() {
    cout << "Hello world! digital" << endl;
    //RobotDrive drive("P9_14", "P9_16");
    //PWM pwm("P9_14");
    //pwm.set(100);
    const char *pin = "P8_3";
    exportGpio(pin);
    digitalMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    sleep(3);
    digitalWrite(pin, LOW);
    unexportGpio(pin);

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
