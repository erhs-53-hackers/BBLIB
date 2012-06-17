#pragma once
#include "PWM.hpp"
#include "Serial.hpp"
#include "Driveable.hpp"
#include <stdlib.h>
extern "C" {
#include <bbmath.h>
}

class RobotDrive {
public:
    RobotDrive(Driveable *left, Driveable *right){
        isRightInverted = false;
        isLeftInverted = false;
        this->left = left;
        this->right = right;
    }
    ~RobotDrive() {
        move(0,0);

    }

    void mapValues(long Lmin, long Lmax, long Rmin, long Rmax) {
        this->Lmin  = Lmin;
        this->Lmax = Lmax;
        this->Rmin  = Rmin;
        this->Rmax = Rmax;
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


        if(isRightInverted) right->set(map(R,-1, 1, Rmin, Rmax));
        else right->set(map(R * -1,-1, 1, Rmin, Rmax));

        if(isLeftInverted) left->set(map(L,-1, 1, Lmin, Lmax));
        else left->set(map(L * -1,-1, 1, Lmin, Lmax));





        printf("left: %f, right: %f\n", L, R);
        printf("Lval: %f, Rval: %f\n", map(L,-1, 1, Lmin, Lmax), map(R,-1, 1, Rmin, Rmax));



    }
    bool isRightInverted, isLeftInverted;

private:
    Driveable *left, *right;
    long Rmin, Rmax, Lmin, Lmax;


};
