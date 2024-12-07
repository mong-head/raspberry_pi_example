#include <wiringPi.h>

#define LED_PWM_PIN 1 // pwm function pin

int main(void){
    int nBright = 0;

    wiringPiSetup();

    pinMode(LED_PWM_PIN, PWM_OUTPUT);

    // led pwm
    while(1){
        for(nBright=0;nBright<1024;nBright++){
            pwmWrite(LED_PWM_PIN, nBright);
            delay(1);
        }
        for(nBright=1023;nBright>=0;nBright--){
            pwmWrite(LED_PWM_PIN, nBright);
            delay(1);
        }
    }
    return 0;
}