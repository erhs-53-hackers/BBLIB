#include <iostream>
#include <list>
#include <pthread.h>

#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

extern "C"{
#include "bbio.h"
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

void delay_micro(long int ms) {
    struct timeval tv;
    ms *= 10;
    gettimeofday(&tv, NULL);
    time_t s = tv.tv_usec;
    while(ms<abs(tv.tv_usec-s)) {
        gettimeofday(&tv, NULL);
    }
}

int main() {
    cout << "Hello world" << endl;
    pinDemo();
    



    return 0;
}
