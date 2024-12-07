#include <wiringPi.h>
#include <stdio.h>
#include <signal.h> // signal library
#include <stdlib.h> // exit() function

#define BUZ_PIN 0

void sig_handler(int signo); // ctrl + c signal handler

int main(void){
    signal(SIGINT, (void *)sig_handler);

    wiringPiSetup();

    pinMode(BUZ_PIN, OUTPUT);

    while(1){
        digitalWrite(BUZ_PIN, HIGH);
        delay(1000);
        digitalWrite(BUZ_PIN, LOW);
        delay(1000);
        printf("BUZZER\n");
    }
    return 0;
}

void sig_handler(int signo){
	printf("\n!!!!program termination!!!!\n");
	digitalWrite(BUZ_PIN, LOW);
	
	exit(0);
}