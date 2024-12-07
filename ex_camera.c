#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPTURE_PUSH_PIN 7

int main(void){
    int oldPushSW = HIGH;
    int pushedSW = LOW;
    int idx = 1;

    wiringPiSetup();

    pinMode(CAPTURE_PUSH_PIN, INPUT);

    while(1){
        pushedSW = digitalRead(CAPTURE_PUSH_PIN);

        if((oldPushSW != pushedSW) && (pushedSW == LOW)) {
            // char cmd[] = "raspistill -w 320 -h 240 -o /home/user/Pictures/test";
            char cmd[] = "fswebcam /home/user/Pictures/webcam";
            char file[3] = {};
            sprintf(file, "%d", idx++);
            strcat(cmd, file);
            strcat(cmd, ".jpg");
            system(cmd);
            printf("TAKE A PICTURE\n");
        }
        oldPushSW = pushedSW;
    }

    return 0;
}