#include <wiringPi.h>
#include <stdio.h>
#include <signal.h> // signal library
#include <stdlib.h> // exit() function

#define PIR_PIN 29
#define LED_PIN 1

void sig_handler(int signo); // ctrl + c signal handler

int main(void){
    signal(SIGINT, (void *)sig_handler);

    wiringPiSetup();

    pinMode(PIR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);

    while(1){
        int detect = digitalRead(PIR_PIN);
        if(detect){
            printf("DETECTED %d\n",detect);
        } else {
            printf("--------\n");
        }
        digitalWrite(LED_PIN, detect);
    }
    return 0;
}
void sig_handler(int signo){
	printf("\n!!!!program termination!!!!\n");
	digitalWrite(LED_PIN, LOW);
	
	exit(0);
}