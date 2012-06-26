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

    muxPin("P9_21", 1);

    Serial serial(PORT, B19200);
    RobotDrive drive(&serial, &serial);
    drive.mapValues(1+30, 127-30, 128+30, 255-30);

    const double speed = 0.7;
    drive.move(speed, 0);
    sleep(2);
    drive.move(-speed, 0);
    sleep(2);
    drive.move(0, speed);
    sleep(2);
    drive.move(0, -speed);
    sleep(2);
    drive.move(0,0);



    /*
    cout << "yo"<<endl;
    muxPin("P9_21", 1);

    Serial serial(PORT, B19200);

    //serial.writeInt(64);
    //serial.writeInt(192);


    for(int i=1+30; i<128-30; i++) {//128
        cout <<"writing: " << i << endl;
        serial.writeInt(i);
        serial.writeInt(192);
        usleep(100000);
    }
    cout <<"writing: " << 64 << endl;
    serial.writeInt(64);

    for(int i=128+30; i<256-30; i++) {//128
        cout <<"writing: " << i << endl;
        serial.writeInt(i);
        serial.writeInt(64);
        usleep(100000);
    }
    cout <<"writing: " << 192 << endl;
    serial.writeInt(192);
    */


    //serial.writeString("HOW IS YOU BE DOINZZZZZZZ!\n");





    return 0;
}
