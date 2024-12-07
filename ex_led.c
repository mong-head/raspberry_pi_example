#include <wiringPi.h>
#include <stdio.h>
#include <signal.h> // signal library
#include <stdlib.h> // exit() function

#define LED_PIN 29

void sig_handler(int signo); // ctrl + c signal handler

int main(void){
	signal(SIGINT, (void *)sig_handler);
	wiringPiSetup();
	
	// LED init
	pinMode(LED_PIN, OUTPUT);
	digitalWrite(LED_PIN, LOW);
	
	while(1){
		// LED ON
		digitalWrite(LED_PIN, HIGH);
		printf("LED ON\n");
		delay(1000);
		
		// LED OFF
		digitalWrite(LED_PIN, LOW);
		printf("LED OFF\n");
		delay(1000);
	}
	return 0;
}

void sig_handler(int signo){
	printf("\n!!!!program termination!!!!\n");
	digitalWrite(LED_PIN, LOW);
	
	exit(0);
}
