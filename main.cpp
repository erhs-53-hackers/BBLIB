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
    cout << "Hello world!" << endl;
    //pinDemo();
    
    char *pwm = "P9_16";
    muxPin(pwm, 6); 
    cout<<"0%"<<endl;
    sleep(1);  
    for(int i=0;i<10;i++) {
    	pwmWrite(pwm, 200, (i+1)*10, 1);
    	cout<<(i+1)*10<<"%"<<endl;
    	sleep(1);    
    }
    for(int i=0;i<10;i++) {
    	pwmWrite(pwm, 200, (10-i)*10, 1);
    	cout<<(10-i)*10<<"%"<<endl;
    	sleep(1);    
    }
    pwmWrite(pwm, 0, 0, 0);
    cout<<"0%"<<endl;
    /*
    exportPin(led);
    
    digitalMode(led, OUTPUT);
    
    
    for(int i=0;i<10;i++) {
    	digitalWrite(led, HIGH);
    	cout << "write HIGH"<<endl;
    	sleep(1);
    	digitalWrite(led, LOW);
    	cout << "write LOW"<<endl;
    	sleep(1);    
    }
    
    unExport(led);
    */
    



    return 0;
}
