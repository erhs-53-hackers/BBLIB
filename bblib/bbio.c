#include "bbio.h"
#include "gperf_pinMap.h"
void pinDemo() {
    char buf[BUFSIZ];
    while (gets (buf)) {
       const struct pin *p = getPin(buf, strlen (buf));
       if(p) printf ("ID = %s\ngpio = %i\nmux = %s\neeprom = %i\npwm = %s\n", p->ID, p->gpio, p->mux, p->eeprom, p->pwm);
       else printf("nope\n");
    }
}

int checkPin(const struct pin *p, int mode) {
    if(!p) return 0;
    switch(mode){
        case 0:
            if(p->gpio != -1) return 1;
        break;
        case 1:
            if(p->mux != NULL) return 1;
        break;
        case 2:
            if(p->eeprom != -1) return 1;
        break;
        case 3:
            if(p->pwm != NULL) return 1;
        break;
    }
    return 0;
}


void digitalWrite(const char *pin, int value) {
    const struct pin *p = getPin(pin, strlen(pin));

    if(checkPin(p, 0) == 0) {
        printf("Error: %s is not a digital pin\n", pin);
        return;
    }

    char buf[29];
    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%i/value", p->gpio);

    FILE *file = fopen(buf, "w");

    if(value) fputc('1', file);
    else      fputc('0', file);

    fclose(file);

}

void fastDigitalWrite(const char *pin, int value) {

    FILE *file = fopen(pin, "w");

    if(value) fputc('1', file);
    else      fputc('0', file);

    fclose(file);

}

int digitalRead(const char *pin) {
    const struct pin *p = getPin(pin, strlen(pin));

    if(checkPin(p, 0) == 0) {
        printf("Error: %s is not a digital pin\n", pin);
        return 0;
    }
    char buf[29];

    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%i/value", p->gpio);


    FILE *file = fopen(buf, "r");

    char value = fgetc(file);

    fclose(file);

    if(value == '1') return 1;




    return 0;
}

int fastDigitalRead(const char *pin) {
    FILE *file = fopen(pin, "r");
    char value = fgetc(file);
    fclose(file);
    if(value == '1') return 1;
    return 0;
}


void exportGpio(const char *pin) {
    const struct pin *p = getPin(pin, strlen(pin));

    if(checkPin(p, 0) == 0) {
        printf("Error: %s is not gpio capable\n", pin);
        return;
    }
    FILE *file = fopen("/sys/class/gpio/export", "w");

    char num[3];

    snprintf(num, sizeof(num), "%i", p->gpio);

    fputs(num, file);

    fclose(file);
}

void unexportGpio(const char *pin) {
    const struct pin *p = getPin(pin, strlen(pin));

    if(checkPin(p, 0) == 0) {
        printf("Error: %s is not a gpio pin\n", pin);
        return;
    }
    FILE *file = fopen("/sys/class/gpio/unexport", "w");
    char num[3];
    snprintf(num, sizeof(num), "%i", p->gpio);

    fputs(num, file);

    fclose(file);
}

void digitalMode(const char *pin, int mode) {
    const struct pin *p = getPin(pin, strlen(pin));

    if(checkPin(p, 0) == 0) {
        printf("Error: %s is not a digital pin\n", pin);
        return;
    }

    char buf[33];

    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%i/direction", p->gpio);

    FILE *file = fopen(buf, "w");

    if(mode) fputs("out", file);
    else     fputs("in", file);

    fclose(file);

}

void fastDigitalMode(const char *pin, int mode) {
    FILE *file = fopen(pin, "w");

    if(mode) fputs("out", file);
    else     fputs("in", file);

    fclose(file);

}

long pulseIn(const char *pin, int value, double timeout) {
    struct timeval tempo1, tempo2;

    long elapsed_utime;    /* elapsed time in microseconds */
    //long elapsed_mtime;    /* elapsed time in milliseconds */
    long elapsed_seconds;  /* diff between seconds counter */
    long elapsed_useconds; /* diff between microseconds counter */
    //gettimeofday(&tempo1, NULL);

    gettimeofday(&tempo1, NULL);
    //puts("waiting for start");
    while(1) {
        if(digitalRead(pin) == value) {
            gettimeofday(&tempo1, NULL);

            //last = tv.tv_usec;
            break;
        }

        gettimeofday(&tempo2, NULL);
        elapsed_seconds  = tempo2.tv_sec  - tempo1.tv_sec;
        elapsed_useconds = tempo2.tv_usec - tempo1.tv_usec;
        elapsed_utime = (elapsed_seconds) * 1000000 + elapsed_useconds;

        if(elapsed_utime >= timeout * 1000000) return -1;
    }



    //puts("waiting for end");

    while(1) {
        if(digitalRead(pin) != value) {
            gettimeofday(&tempo2, NULL);

            break;
        }
        gettimeofday(&tempo2, NULL);
        elapsed_seconds  = tempo2.tv_sec  - tempo1.tv_sec;
        elapsed_useconds = tempo2.tv_usec - tempo1.tv_usec;
        elapsed_utime = (elapsed_seconds) * 1000000 + elapsed_useconds;

        if(elapsed_utime >= timeout * 1000000) return -1;
    }

    elapsed_seconds  = tempo2.tv_sec  - tempo1.tv_sec;
    elapsed_useconds = tempo2.tv_usec - tempo1.tv_usec;

    elapsed_utime = (elapsed_seconds) * 1000000 + elapsed_useconds;
    //elapsed_mtime = ((elapsed_seconds) * 1000 + elapsed_useconds/1000.0) + 0.5;
    return elapsed_utime;
}

long fastPulseIn(const char *pin, int value) {
    struct timeval tv;
    double last, time = 0;
    gettimeofday(&tv, NULL);
    last = tv.tv_usec;


    while(1) {
        if(fastDigitalRead(pin) != value) {
            break;
        }
        gettimeofday(&tv, NULL);

        time += abs(last - tv.tv_usec);
        last = tv.tv_usec;
    }

    return time;
}

void muxPin(const char* pin, int mode) {
    const struct pin *p = getPin(pin, strlen(pin));

    if(checkPin(p, 0) == 0) {
        printf("Error: pin %s cannot be muxed\n", pin);
        return;
    }
    char buf[44];

    snprintf(buf, sizeof(buf), "/sys/kernel/debug/omap_mux/%s", getPin(pin, strlen(pin))->mux);
    FILE *file = fopen(buf, "w");


    fprintf(file, "%x", mode);



    fclose(file);
}

void pwmWrite(const char* pin, int frequency, int percent, int isrun) {
    const struct pin *p = getPin(pin, strlen(pin));

    if(checkPin(p, 3) == 0) {
        printf("Error: %s is not pwm capable\n", pin);
        return;
    }
    char pwm[26] = "/sys/class/pwm/";
    strcat(pwm, getPin(pin, strlen(pin))->pwm);

    char duty_percent[39] = "";
    strcat(duty_percent, pwm);
    strcat(duty_percent, "/duty_percent");

    char period_freq[38] = "";
    strcat(period_freq, pwm);
    strcat(period_freq, "/period_freq");

    char run[30] = "";
    strcat(run, pwm);
    strcat(run, "/run");

    FILE *file = fopen(period_freq, "w");
    fprintf(file,"%i", frequency);
    fclose(file);


    file = fopen(duty_percent, "w");
    fprintf(file, "%i", percent);
    fclose(file);


    if(isrun == 1) {
    	file = fopen(run, "w");
    	fputs("1", file);
    	fclose(file);
    } else {
    	file = fopen(run, "w");
    	fputs("0", file);
    	fclose(file);
    }


}

