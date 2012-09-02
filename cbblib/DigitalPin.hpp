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

    void on() {
        if(pin == NULL) {
            puts("Pin not initialized!");
            return;
        }
        if(mode == INPUT) {
            muxPin(pin, 0x37);
            digitalMode(pin, OUTPUT);
            mode = OUTPUT;
        }

        digitalWrite(pin, HIGH);
    }

     void off() {
        if(pin == NULL) {
            puts("Pin not initialized!");
            return;
        }
        if(mode == INPUT) {
            muxPin(pin, 0x37);
            digitalMode(pin, OUTPUT);
            mode = OUTPUT;
        }

        digitalWrite(pin, LOW);
    }

    void set(int value) {
        if(pin == NULL) {
            puts("Pin not initialized!");
            return;
        }
        if(mode == INPUT) {
            muxPin(pin, 0x37);
            digitalMode(pin, OUTPUT);
            mode = OUTPUT;
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
            mode = OUTPUT;
        }

        return digitalRead(pin);
    }

    long pulse(int mode, double timeout = 5) {
        if(pin == NULL) {
            puts("Pin not initialized!");
            return 0;
        }
        if(this->mode == OUTPUT){
            muxPin(pin, 0x27);
            digitalMode(pin, INPUT);
            this->mode = INPUT;
        }

        return pulseIn(pin, mode, timeout);
    }


private:
    const char *pin;
    int mode;

};
