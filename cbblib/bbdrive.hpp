#pragma once
#include "PWM.hpp"
extern "C" {
#include <bbmath.h>
}

class RobotDrive {
public:
    RobotDrive() {
        isRightInverted = false;
        isLeftInverted = false;
    }
    RobotDrive(const char *left, const char *right) {
        isRightInverted = false;
        isLeftInverted = false;
        attach(left, right);
    }
    void attach(const char *Lmotor, const char *Rmotor) {
        left.attach(Lmotor);
        right.attach(Rmotor);
    }

    void move(double rotate, double move) {
        double L, R;
        if (move > 0.0) {
            if (rotate > 0.0) {
                L = move - rotate;
                R = max(move, rotate);
            } else {
                L = max(move, -rotate);
                R = move + rotate;
            }
        } else {
            if (rotate > 0.0) {
                L = -max(-move, rotate);
                R = move + rotate;
            } else {
                L = move - rotate;
                R = -max(-move, -rotate);
            }
        }

        right.set(map(R, -1.0, 1.0, 0, 100));
        //else right.set(_map(R, -1.0, 1.0, 84 * 2, 0));

        left.set(map(L, -1.0, 1.0, 0, 100));
        //else left.write(_map(L, -1.0, 1.0, 84 * 2, 0));

    }
    bool isRightInverted, isLeftInverted;

private:
    PWM right, left;

};
