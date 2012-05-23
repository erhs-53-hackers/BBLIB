#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include "PWM.hpp"

extern "C" {
    #include <bbio.h>
}
using namespace std;

bool isDebugMode() {
    //true  : debug
    //false : run
    const char *pin = "P8_3";
    exportGpio(pin);
    digitalMode(pin, INPUT);
    
    bool value = digitalRead(pin);
    
    return value;    
}

int main() {
    if(isDebugMode()){
        cout << "DEBUG MODE" <<endl;
        return 0;
    }
    cout << "RUN MODE" << endl;
    PWM pwm("P9_14");
    puts("init");

    pwm.set(100);
    puts("set\n");
    sleep(5);
    pwm.stop();
    puts("stop");
    sleep(1);
    puts("done =)");
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
