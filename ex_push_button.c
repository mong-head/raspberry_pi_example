#include <wiringPi.h>
#include <stdio.h>

#define PUSH_PIN 25

int main(void){
    // init
    wiringPiSetup();

    // set sensor pin 
    pinMode(PUSH_PIN, INPUT);

    // print button input value
    while(1){
        printf("PUSH VALUE = %d\n", digitalRead(PUSH_PIN));
    }
    return 0;
}