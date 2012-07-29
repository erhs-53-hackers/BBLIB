#pragma once
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <string>
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

        //fcntl(fd, F_SETFL, FNDELAY);//makes read() return 0 if no characters instead of waiting

        fcntl(fd, VMIN, 1);//min # of chars
        fcntl(fd, VTIME, 10);//timeout

        options.c_cflag |= CS8|CLOCAL;
        options.c_oflag &= ~OPOST;
        options.c_iflag |= (INPCK | ISTRIP);
        options.c_iflag |= (IXON | IXOFF | IXANY);
        options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

        tcsetattr(fd, TCSADRAIN, &options);
    }
    ~Serial() {
        close(fd);
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

    std::string readString() {
        char buffer[20] = "";
        int n = read(fd, buffer, sizeof(buffer));
        if (n < 0) fputs("read failed!\n", stderr);
        //puts(buffer);

        return std::string(buffer);
    }


    //void write_(std::string str) {
        //write(fd, str.c_str(), str.size());
    //}
private:
    int fd;

};
