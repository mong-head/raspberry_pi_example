#include <wiringPi.h>
#include <stdio.h>
#include <signal.h> // signal library
#include <stdlib.h> // exit() function

#define LED_PIN 29
#define PUSH_PIN 25

void sig_handler(int signo); // ctrl + c signal handler

int main(void){
	signal(SIGINT, (void *)sig_handler);
	wiringPiSetup();
	
	// LED init
	pinMode(LED_PIN, OUTPUT);
	digitalWrite(LED_PIN, LOW);

    // set sensor pin 
    pinMode(PUSH_PIN, INPUT);
	
	while(1){
        if(digitalRead(PUSH_PIN) == 1){
		    // LED ON
            digitalWrite(LED_PIN, HIGH);
		    // printf("LED ON\n");
        } else {
            // LED OFF
            digitalWrite(LED_PIN, LOW);
            // printf("LED OFF\n");
        }
	}
	return 0;
}

void sig_handler(int signo){
	printf("\n!!!!program termination!!!!\n");
	digitalWrite(LED_PIN, LOW);
	
	exit(0);
}
