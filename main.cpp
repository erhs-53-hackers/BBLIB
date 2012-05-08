#include <iostream>
#include <list>
#include <pthread.h>
#include "bbio.h"
using namespace std;

int main() {


    cout << "Hello world!" << endl;
    exportPin(38);
    digitalMode(38, OUTPUT);

    exportPin(47);
    digitalMode(47, INPUT);

    digitalWrite(38, 1);

    for(int i=0;i<5000;i++) {
        cout << digitalRead(47) <<endl;
    }

    digitalWrite(38, 0);
    unExport(38);
    unExport(47);

    return 0;
}
