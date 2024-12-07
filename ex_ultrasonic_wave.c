#include <wiringPi.h>
#include <stdio.h>
#include <signal.h> // signal library
#include <stdlib.h> // exit() function

#define TRIG_PIN 4
#define ECHO_PIN 5
#define LED_PIN 29

void sig_handler(int signo); // ctrl + c signal handler
int main(void){
    int start_time, end_time;
    float distance;

    signal(SIGINT, (void *)sig_handler);

    wiringPiSetup();
    // ultrasonic
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    // led
    pinMode(LED_PIN, OUTPUT);
	digitalWrite(LED_PIN, LOW);

    while(1){
        digitalWrite(TRIG_PIN, LOW);
        delay(500);

        digitalWrite(TRIG_PIN, HIGH);
        delayMicroseconds(10);
        digitalWrite(TRIG_PIN, LOW);

        while(digitalRead(ECHO_PIN) == LOW){
            start_time = micros();
        }
        while(digitalRead(ECHO_PIN) == HIGH){
            end_time = micros();
        }
    
        /* ultrasonic wave */
        // (331.5 + 0.6*25) : velocity,25 : room temperature
        distance = (331.5 + 0.6*25)*((float)(end_time - start_time)/1000000/2)*100;
        printf("DISTANCE : %3.1f cm\n",distance);
        
        /* led */
        if(distance <= 50){
            digitalWrite(LED_PIN, HIGH);
        } else {
            digitalWrite(LED_PIN, LOW);
        }
    }
    return 0;
}

void sig_handler(int signo){
	printf("\n!!!!program termination!!!!\n");
	digitalWrite(LED_PIN, LOW);
	
	exit(0);
}