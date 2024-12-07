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


int main(void){
    float Vref = 5.0;

    wiringPiSetup();
    pcf8591Setup(BASE, Address);

    while(1){
        analogWrite(BASE, 50); // AOUT pin 50/255*5V
        delay(5000);
         analogWrite(BASE, 100); // AOUT pin 100/255*5V
        delay(5000);
         analogWrite(BASE, 150); // AOUT pin 150/255*5V
        delay(5000);
         analogWrite(BASE, 200); // AOUT pin 200/255*5V
        delay(5000);
         analogWrite(BASE, 255); // AOUT pin 2550/255*5V
        delay(5000);
    }

    return 0;
}