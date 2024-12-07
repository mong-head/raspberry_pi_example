#include <stdio.h>
#include <wiringPi.h>
#include <pcf8591.h>
#include <signal.h> // signal library
#include <stdlib.h> // exit() function

#define Address 0x48
#define BASE 64
#define AIN0 BASE+0
#define AIN1 BASE+1
#define AIN2 BASE+2
#define AIN3 BASE+3
#define LED_PIN 29

void sig_handler(int signo); // ctrl + c signal handler

int main(void){
    float Vref = 5.0;
    float value0 = 0;

    signal(SIGINT, (void *)sig_handler);
    wiringPiSetup();
    pcf8591Setup(BASE, Address);
    // LED init
	pinMode(LED_PIN, OUTPUT);
	digitalWrite(LED_PIN, LOW);

    while(1){
        value0 = analogRead(AIN0);
        printf("AIN 0 (Trimpot) : %2.1f [V]\n", (value0/255)*Vref);
        if((value0/255)*Vref > 3.0) {
            analogWrite(BASE,255);
            digitalWrite(LED_PIN, HIGH);
        } else {
            analogWrite(BASE,0);
            digitalWrite(LED_PIN, LOW);
        }

        delay(10);
    }

    return 0;
}

void sig_handler(int signo){
	printf("\n!!!!program termination!!!!\n");
	digitalWrite(LED_PIN, LOW);
	
	exit(0);
}