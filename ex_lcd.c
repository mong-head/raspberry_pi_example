#include <wiringPi.h>
#include <lcd.h>
#include <stdio.h>

#define LCD_RS 11 // register select pin
#define LCD_E 10 // enable pin
#define LCD_D4 6 // data pin 4
#define LCD_D5 5 // data pin 5
#define LCD_D6 4 // data pin 6
#define LCD_D7 1 // data pin 7

int main(void){
    int lcd;
    wiringPiSetup();

    lcd = lcdInit(2,16,4,LCD_RS,LCD_E,LCD_D4,LCD_D5,LCD_D6,LCD_D7,0,0,0,0);
    printf("lcd %d",lcd);
    if(lcd){
        printf("LCD INIT FAILED \n");
        return -1;
    }
    lcdPosition(lcd,0,0);
    lcdPuts(lcd, "HELLO WORLD");

    char inputchar[20];
    scanf("%s",inputchar);
    lcdClear(lcd);
    lcdPuts(lcd, inputchar);

    return 0;
}