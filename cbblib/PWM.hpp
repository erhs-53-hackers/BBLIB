#pragma once
extern "C" {
    #include <bbio.h>
    #include <stdio.h>
}

class PWM {
public:
    PWM() {}
    PWM(const char *pin) {
        attach(pin);
    }
    void attach(const char *pin) {
        pwm = pin;
        muxPin(pin, 6);
        stop();
    }
    void set(int percent) {
        pwmWrite(pwm, 200, percent, 1);
    }
    void stop() {
        pwmWrite(pwm, 0, 0, 0);
    }
protected:
private:
    const char *pwm;
};


