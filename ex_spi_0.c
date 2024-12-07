#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include <wiringPi.h>
#include<wiringPiSPI.h>

#define CHAN_CONFIG_SINGLE 8
#define CHAN_CONFIG_DIFF 0

static int myFd;

void spiSetup(int spiChannel){
    if((myFd = wiringPiSPISetup(spiChannel, 1000000)) < 0){
        fprintf(stderr, "Can't open the SPI bus: %s",strerror(errno));
        exit(EXIT_FAILURE);
    }
}

int myAnalogRead(int spiChannel, int channelConfig, int analogChannel){
    if(analogChannel <0 || analogChannel > 3) return -1;

    unsigned char buffer[3] = {1};
    buffer[1] = (channelConfig + analogChannel) << 4;

    wiringPiSPIDataRW(spiChannel, buffer, 3);

    return ((buffer[1] & 3) << 8) + buffer[2];
}

int main(void){
    int analogChannel = 0;
    int spiChannel = 1;
    int channelConfig = CHAN_CONFIG_SINGLE;
    int i;
    int vref = 5;
    float volt;

    wiringPiSetup();
    spiSetup(spiChannel);

    for(i=0;i<10;i++){
        volt = myAnalogRead(spiChannel, channelConfig, analogChannel);

        printf("Voltage = %3.2f\n", (volt/1023)*vref);
        delay(500);
    }

    close(myFd);
    return 0;
}