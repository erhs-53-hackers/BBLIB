#pragma once
extern "C" {
#include <bbmath.h>
}

class Robot {
public:
    Robot() {
        isRightInverted = false;
        isLeftInverted = false;
    }
    void attach(int Lmotor, int Rmotor) {}

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

        //if(isRightInverted) right.write(_map(R, -1.0, 1.0, 0, 84 * 2));
        //else right.write(_map(R, -1.0, 1.0, 84 * 2, 0));

        //if(isLeftInverted) left.write(_map(L, -1.0, 1.0, 0, 84 * 2));
        //else left.write(_map(L, -1.0, 1.0, 84 * 2, 0));

    }
    bool isRightInverted, isLeftInverted;

private:
    //Servo right, left;

};
