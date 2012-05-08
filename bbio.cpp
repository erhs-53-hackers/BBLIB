
#include "bbio.h"

using namespace std;




void Pin::setMode(int mode) {
    std::ofstream file("/sys/class/gpio/export");
    if(!file) {
        throw 1;
    }
    file << pin;
    file.close();

    std::string pin_str;
    std::stringstream out;
    out << "/sys/class/gpio/gpio" << pin << "/direction";
    pin_str = out.str();

    std::cout << "using \"" << pin_str << "\"" << std::endl;

    file.open(pin_str.c_str());

    if(mode == INPUT) {
        file << "in";
    } else {
        file << "out";
    }
    file.close();

}

void Pin::unexport() {
    std::ofstream file("/sys/class/gpio/unexport");
    file << pin;
    file.close();
}



DigitalPin::DigitalPin() {

}

DigitalPin::DigitalPin(int pin, int mode) {
    cout << "setting up pin:" <<endl;
    setPin(pin);
    cout << "setting mode:" <<endl;
    setMode(mode);


}

DigitalPin::~DigitalPin() {
    unexport();
}

void DigitalPin::setPin(int _pin) {
    cout << "using pin" << _pin<<endl;
    pin = digitalPinNum[_pin];
}

void DigitalPin::write(int value) {
    std::string pin_str;
    std::stringstream out;
    out << "/sys/class/gpio/gpio" << pin << "/value";
    pin_str = out.str();

    std::ofstream file(pin_str.c_str());

    file << value;

    file.close();
}

int DigitalPin::read() {
    return 1;
}



void digitalWrite(int pin, int value) {
    std::string pin_str;
    std::stringstream out;
    out << "/sys/class/gpio/gpio" << pin << "/value";
    pin_str = out.str();

    std::ofstream file(pin_str.c_str());

    file << value;

    file.close();
}

int digitalRead(int pin) {
    std::string pin_str;
    std::stringstream out;
    out << "/sys/class/gpio/gpio" << pin << "/value";
    pin_str = out.str();

    std::ifstream file(pin_str.c_str());

    string value;

    std::getline(file, value);

    if(value == "1") {
        return 1;
    }

    return 0;
}

void exportPin(int pin) {
    std::ofstream file("/sys/class/gpio/export");

    file << pin;

}

void unExport(int pin) {
    std::ofstream file("/sys/class/gpio/unexport");

    file << pin;
}

void digitalMode(int pin, int mode) {
    std::string pin_str;
    std::stringstream out;
    out << "/sys/class/gpio/gpio" << pin << "/direction";
    pin_str = out.str();

    std::ofstream file(pin_str.c_str());

    if(mode == 1) {
        file << "out";
    } else {
        file << "in";
    }
}

