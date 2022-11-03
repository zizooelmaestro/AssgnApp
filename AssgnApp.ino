#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"
#include "dio.h"
#include "uart.h"
#include <stdlib.h>

int store_LDR;
int i;
int n;
#define thresh 400
//void init();

int main(void){
  init();
  
  while (1)
  {
    // code will run repeatedly
    // switch and LED 
    int switch_press = (PINB & (1 << 3))!= 0;
    if(switch_press)  // if switch not pressed
    {
      PORTB = PORTB & ~(1 << 5);    // Switch OFF LED
     // _delay_ms(200);
    }  
    else 
    {
      PORTB = PORTB | (1 << 5);      // Switch ON LED
      _delay_ms(200);
      uart_sendstring("kEY IS PRESSED \n");
    }
    //LDR and LED
    
    store_LDR = Adc_ReadChannel(0);
    // convert store_LDR to string
    char str[10]={0};
    itoa(store_LDR, str, 10);
    // UART SEND store_LDR string form
    uart_sendstring(str);
    
    if(store_LDR > thresh){
      // If LDR reads low readings we will have to turn the LED on
      PORTB = PORTB | (1 << 0);      // Switch ON LED
      _delay_ms(200);
      // Uart send warning
      uart_sendstring("WARNING \n");
    }
    else{
      // If LDR reads high readings we will turn the LED off
      PORTB = PORTB & ~(1 << 0);     // Switch off LED
      _delay_ms(200);
    }
    // time referance LED for switch
  /*  if(switch_press){
       i=1;
       n=0;
      for(i;i==n+1;i++){
        PORTB = PORTB |(1<<2);
        _delay_ms(200);
        PORTB = PORTB &~(1<<2);
        _delay_ms(200);
        n=1;
      }
         
    delay(10000);
    i=i+n;
    } 

 // time referance Potentiometer for switch
    if(store_LDR < thresh){
       i=1;
       n=0;
      for(i;i < n+1 ; i++){
        PORTB = PORTB |(1<<4);
        _delay_ms(200);
        PORTB = PORTB &~(1<<4);
        _delay_ms(200);
        n = 1;
      }
    
    delay(10000);
    i=i+n;
    }*/
    
  }
  return 0;
}

void init()
{
  // code will run once
  // Initalization of libraries

  Adc_Init();
  uart_init(9600);
  Dio_Init();
  
  }
