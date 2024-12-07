#include <wiringPi.h>
#include <softTone.h>
#include <stdio.h>
#include <signal.h> // signal library
#include <stdlib.h> // exit() function

#define BUZ_PIN 0

const int DO=262;
const int RE=294;
const int MI=330;
const int FA=349;
const int SOL=392;
const int LA=440;
const int TI=494;
const int DO_HIGH=523;
unsigned int melody[8] = {DO, RE, MI, FA, SOL, LA, TI, DO_HIGH};
int notes[] = {
 391, 391, 440, 440, 391, 391, 329.63, 329.63,
 391, 391, 329.63, 329.63, 293.66, 293.66, 293.66, 0,
 391, 391, 440, 440, 391, 391, 329.63, 329.63,
 391, 329.63, 293.66, 329.63, 261.63, 261.63, 261.63, 0
};

void sig_handler(int signo); // ctrl + c signal handler
int main(void){
    signal(SIGINT, (void *)sig_handler);

    wiringPiSetup();

    softToneCreate(BUZ_PIN);

    for(int idx=0;idx<sizeof(notes);idx++){
        softToneWrite(BUZ_PIN, notes[idx]);
        delay(240);
    }
    softToneStop(BUZ_PIN);
    return 0;
}

void sig_handler(int signo){
	printf("\n!!!!program termination!!!!\n");
    softToneStop(BUZ_PIN);
	exit(0);
}