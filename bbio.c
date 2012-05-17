#include "bbio.h"
#include "gperf_pinMap.h"
void pinDemo() {
    char buf[BUFSIZ];
    while (gets (buf)) {
       struct pin *p = getPin(buf, strlen (buf));
       if(p) printf ("ID = %s\ngpio = %i\nmux = %s\neeprom = %i\npwm = %s\n", p->ID, p->gpio, p->mux, p->eeprom, p->pwm);
       else printf("nope\n");
    }
}

int checkPin(struct pin *p, int mode) {
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
    struct pin *p = getPin(pin, strlen(pin));
    
    if(checkPin(p, 0) == 0) {
        printf("Error: %s is not a digital pin", pin);
        return;
    }
    
    char buf[29];
    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%i/value", getPin(pin, strlen(pin))->gpio);

    FILE *file = fopen(buf, "w");    

    if(value) fputc('1', file);
    else      fputc('0', file);

    fclose(file); 
    
}

int digitalRead(const char *pin) {    
    char buf[29];

    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%i/value", getPin(pin, strlen(pin))->gpio);


    FILE *file = fopen(buf, "r");

    char value = fgetc(file);

    fclose(file);

    if(value == '1') return 1;




    return 0;
}

void exportPin(const char *pin) {
    FILE *file = fopen("/sys/class/gpio/export", "w");   
    
    char num[3];    
    
    snprintf(num, sizeof(num), "%i", getPin(pin, strlen(pin))->gpio);    

    fputs(num, file);    

    fclose(file);
}

void unExport(const char *pin) {
    FILE *file = fopen("/sys/class/gpio/unexport", "w");
    char num[3];
    snprintf(num, sizeof(num), "%i", getPin(pin, strlen(pin))->gpio);

    fputs(num, file);

    fclose(file);
}

void digitalMode(const char *pin, int mode) {

    char buf[33];

    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%i/direction", getPin(pin, strlen(pin))->gpio);

    FILE *file = fopen(buf, "w");

    if(mode) fputs("out", file);
    else     fputs("in", file);

    fclose(file);

}

long pulseIn(const char *pin, int value) {
    struct timeval tv;

    gettimeofday(&tv, NULL);
    double last, time = 0;

    puts("waiting for initial pulse...\n");
    gettimeofday(&tv, NULL);


    last = tv.tv_usec * 1000;

    while(1) {
        gettimeofday(&tv, NULL);
        double now = tv.tv_usec * 1000;
        if(abs(now - last) > 1000 * 1000)return -1;

        //cout << ".";
        if(digitalRead(pin) == value) {
            gettimeofday(&tv, NULL);

            last = tv.tv_usec;
            break;
        }
    }
    //cout <<endl;
    gettimeofday(&tv, NULL);
    double start = tv.tv_usec * 1000;

    puts("waiting for terminary pulse...\n");
    while(1) {
        gettimeofday(&tv, NULL);
        double now = tv.tv_usec;
        if(abs(now * 1000 - start) > 1000 * 1000)return -1;
        time += abs(last - now);
        last = now;


        //cout << ".";
        if(digitalRead(pin) != value) {
            gettimeofday(&tv, NULL);
            double now = tv.tv_usec;
            time += abs(last - now);

            break;
        }
    }
    // cout<<endl<<"done!"<<endl;

    return time;
}

void muxPin(const char* pin, int mode) {
    char buf[44];

    snprintf(buf, sizeof(buf), "/sys/kernel/debug/omap_mux/%s", getPin(pin, strlen(pin))->mux);
    FILE *file = fopen(buf, "w");
    
    fprintf(file, "%i", mode);
    
    fclose(file);
}

void pwmWrite(const char* pin, int frequency, int percent, int isrun) {
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

