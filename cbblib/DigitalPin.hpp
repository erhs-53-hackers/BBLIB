#pragma once
extern "C" {
    #include <bbio.h>
    #include <stdio.h>
}

class DigitalPin {
public:
    DigitalPin(){pin = NULL;}
    DigitalPin(const char *pin) {
        attach(pin);
    }
    ~DigitalPin() {
        release();
    }

    void release() {
        unexportGpio(pin);
    }

    void attach(const char *pin) {
        this->pin = pin;
        exportGpio(pin);
        muxPin(pin, 0x37);
        digitalMode(pin, OUTPUT);
        mode = OUTPUT;
    }

    void set(int value) {
        if(pin == NULL) {
            puts("Pin not initialized!");
            return;
        }
        if(mode == INPUT) {
            muxPin(pin, 0x37);
            digitalMode(pin, OUTPUT);
        }

        digitalWrite(pin, value);
    }

    int get() {
        if(pin == NULL) {
            puts("Pin not initialized!");
            return 0;
        }
        if(mode == OUTPUT){
            muxPin(pin, 0x27);
            digitalMode(pin, INPUT);
        }

        return digitalRead(pin);
    }

    long pulse(int mode) {
        if(pin == NULL) {
            puts("Pin not initialized!");
            return 0;
        }
        if(mode == OUTPUT){
            muxPin(pin, 0x27);
            digitalMode(pin, INPUT);
        }

        return pulseIn(pin, mode, 5);
    }
private:
    const char *pin;
    int mode;

};
