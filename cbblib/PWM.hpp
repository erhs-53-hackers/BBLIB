#pragma once
extern "C" {
    #include <bbio.h>
    #include <stdio.h>
}

class PWM {
public:
    PWM(const char *pin) {
        pwm = pin;
        muxPin(pin, 6);
        stop();
    }
    void set(int percent) {
        pwmWrite(pwm, 100, percent, 1);
    }
    void stop() {
        pwmWrite(pwm, 0, 0, 0);
    }
protected:
private:
    const char *pwm;
};


