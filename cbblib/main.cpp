#include <iostream>
#include "Ping.hpp"
#include "DigitalPin.hpp"




extern "C" {
#include <bbio.h>
//#include <gperf_pinMap.h>
}
using namespace std;

bool isDebugMode() {
    //true  : debug
    //false : run
    const char *pin = "P8_3";
    DigitalPin gate(pin);
    bool value = gate.get();
    return value;
}

int main() {
    const char* pingPin = "P9_15";

    Ping ping(pingPin);


    while(true) {


        cout << "cm = " << ping.getCm() <<endl;
        usleep(3000);
    }







    return 0;
}
