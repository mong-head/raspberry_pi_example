#include <wiringPi.h>
#include <lcd.h>
#include <stdio.h>
#include <string.h>

#define CAPTURE_PUSH_PIN 7

#define LCD_RS 11 // register select pin
#define LCD_E 10 // enable pin
#define LCD_D4 6 // data pin 4
#define LCD_D5 5 // data pin 5
#define LCD_D6 4 // data pin 6
#define LCD_D7 1 // data pin 7

int main(void){
    int oldPushSW = HIGH;
    int pushedSW = LOW;
    int idx = 1;
    int lcd;

    wiringPiSetup();

    pinMode(CAPTURE_PUSH_PIN, INPUT);
    lcd = lcdInit(2,16,4,LCD_RS,LCD_E,LCD_D4,LCD_D5,LCD_D6,LCD_D7,0,0,0,0);
    if(lcd){
        printf("LCD INIT FAILED \n");
        return -1;
    }

    while(1){
        pushedSW = digitalRead(CAPTURE_PUSH_PIN);

        if((oldPushSW != pushedSW) && (pushedSW == LOW)) {
            char filename[20];
            snprintf(filename, sizeof(filename), "test%d.jpg", idx++);
            lcdPosition(lcd,0,0);
            lcdPuts(lcd, "TAKE A PICTURE");
            lcdPosition(lcd,0,1);
            lcdPuts(lcd, filename);

            char cmd[] = "fswebcam /home/user/Pictures/";
            strcat(cmd, filename);
            system(cmd);
            printf("TAKE A PICTURE\n");
            lcdClear(lcd);
        }
        oldPushSW = pushedSW;
    }

    return 0;
}