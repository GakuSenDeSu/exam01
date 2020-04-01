#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;
PwmOut PWM1(D6);
Serial pc( USBTX, USBRX );
AnalogIn Ain(A0);
float ADCdata;

int main()
{
    //Q2
    // basic printf demo = 16 by 18 characters on screen
    uLCD.printf("\nStarting Demo...\n"); //Default Green on black text
    uLCD.printf("\n  108038520\n");
    uLCD.text_width(4); //4X size text
    uLCD.text_height(4);
    uLCD.color(RED);
    uLCD.filled_rectangle(50, 50, 100, 100, 0xFFFFFF);

    //Q3
    for (int i = 0; i<9; i++){
      PWM1.period(0.001);
      PWM1 = 0.1+0.1*i;
    }
    for (i = 0; i<9; i++){
      PWM1.period(0.001);
      PWM1 = 1.0-0.1*i; 
    }

    //Q4
    ADCdata = Ain;
    wait(0.1);
    pc.printf("%1.3f\r\n", ADCdata);

}



}