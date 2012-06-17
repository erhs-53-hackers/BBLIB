#pragma once
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include "Driveable.hpp"
//#include <string>

class Serial : public Driveable{
public:
    Serial(const char* port, int buadrate) {
        fd = open(port, O_RDWR | O_NOCTTY | O_NDELAY);
        if (fd == -1) {//unable to open port
            perror("open_port: Unable to open port");
        } else
            fcntl(fd, F_SETFL, 0);

        struct termios options;

        tcgetattr(fd, &options);

        cfsetispeed(&options, buadrate);
        cfsetospeed(&options, buadrate);

        options.c_cflag |= (CLOCAL);

        tcsetattr(fd, TCSANOW, &options);
    }

    void writeString(const char* str) {
        write(fd, str, strlen(str));
    }

    void set(int percent){
        writeInt(percent);
    }

    void writeInt(int i) {
        char str[2] = "";
        str[0] = (char)i;
        write(fd, str, strlen(str));
    }


    //void write_(std::string str) {
        //write(fd, str.c_str(), str.size());
    //}
private:
    int fd;

};
