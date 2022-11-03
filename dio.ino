// #include "STD_TYPES.h"
#include "dio.h"

#define SET_BIT(Var,BitNo)       Var |= (1 << (BitNo))
#define CLR_BIT(Var,BitNo)       Var &= ~(1 << (BitNo))
#define TOGGLE_BIT(Var,BitNo)    Var ^= (1 << (BitNo))
#define GET_BIT(Var,BitNo)    (((Var) >> (BitNo)) & 0x01)

#define DIO_u8_PORTA_REG   *((volatile u8*)0X3B)
#define DIO_u8_PORTB_REG   *((volatile u8*)0X38)
#define DIO_u8_PORTC_REG   *((volatile u8*)0X35)
#define DIO_u8_PORTD_REG   *((volatile u8*)0X32)
#define DIO_u8_DDRA_REG   *((volatile u8*)0X3A)
#define DIO_u8_DDRB_REG   *((volatile u8*)0X37)
#define DIO_u8_DDRC_REG   *((volatile u8*)0X34)
#define DIO_u8_DDRD_REG   *((volatile u8*)0X31)
#define DIO_u8_PINA_REG   *((volatile u8*)0X39)
#define DIO_u8_PINB_REG   *((volatile u8*)0X36)
#define DIO_u8_PINC_REG   *((volatile u8*)0X33)
#define DIO_u8_PIND_REG   *((volatile u8*)0X30)

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short int u16;
typedef signed short int s16;
typedef unsigned long int u32;
typedef signed long int s32;
typedef float f32;
typedef double f64;

void Dio_Init(){
  
  DDRB = DDRB | (1 << 5);     // Make PB5 output as it is the first LED
  DDRB = DDRB & ~(1 << 3);    // Make PB3 input as it is the switch
  PORTB = PORTB | (1 << 3);   // Activate pull up resistance
  // defining Potentiometer and LED
  DDRB = DDRB | (1 << 0);     // Make PB0 output as it is the second LED
  //DDRC = DDRC & ~(1 << 1);    // Make Potentiometer as in input
  // defining time referance LEDs
  DDRB = DDRB | (1 << 2);     // Make PB0 output as it is the third LED
  DDRB = DDRB | (1 << 4);     // Make PB0 output as it is the fourth LED
}


void DIO_VoidSetPinDirection(u8 DIO_u8PortId, u8 DIO_u8PinId, u8 DIO_PinDir)
{
  if( (DIO_u8PortId < PORT_MAX) && (DIO_u8PinId < PIN_MAX) && (DIO_PinDir == DIO_u8_INPUT || DIO_PinDir == DIO_u8_OUTPUT) )
  {
    switch(DIO_u8PortId)
    {
    case DIO_u8_PORTA:
    if(DIO_PinDir == DIO_u8_INPUT)
    {
      CLR_BIT(DIO_u8_DDRA_REG,DIO_u8PinId);
    }
    else
    {
      SET_BIT(DIO_u8_DDRA_REG,DIO_u8PinId);
    }
    break;
  case DIO_u8_PORTB:
    if(DIO_PinDir == DIO_u8_INPUT)
    {
      CLR_BIT(DIO_u8_DDRB_REG,DIO_u8PinId);
    }
    else
    {
      SET_BIT(DIO_u8_DDRB_REG,DIO_u8PinId);
    }
    break;
  case DIO_u8_PORTC:
    if(DIO_PinDir == DIO_u8_INPUT)
    {
      CLR_BIT(DIO_u8_DDRC_REG,DIO_u8PinId);
    }
    else
    {
      SET_BIT(DIO_u8_DDRC_REG,DIO_u8PinId);
    }
    break;
  case DIO_u8_PORTD:
    if(DIO_PinDir == DIO_u8_INPUT)
    {
      CLR_BIT(DIO_u8_DDRD_REG,DIO_u8PinId);
    }
    else
    {
      SET_BIT(DIO_u8_DDRD_REG,DIO_u8PinId);
    }
    break;
    }
  }
}

void DIO_VoidSetPinValue(u8 DIO_u8PortId, u8 DIO_u8PinId, u8 DIO_PinVal)
{
  if( (DIO_u8PortId < PORT_MAX) && (DIO_u8PinId < PIN_MAX) && (DIO_PinVal == DIO_u8_HIGH || DIO_PinVal == DIO_u8_LOW) )
  {
    switch(DIO_u8PortId)
    {
    case DIO_u8_PORTA:
      if(DIO_PinVal == DIO_u8_HIGH)
      {
        SET_BIT(DIO_u8_PORTA_REG,DIO_u8PinId);
      }
      else
      {
        CLR_BIT(DIO_u8_PORTA_REG,DIO_u8PinId);
      }
      break;
    case DIO_u8_PORTB:
      if(DIO_PinVal == DIO_u8_HIGH)
      {
        SET_BIT(DIO_u8_PORTB_REG,DIO_u8PinId);
      }
      else
      {
        CLR_BIT(DIO_u8_PORTB_REG,DIO_u8PinId);
      }

      break;
    case DIO_u8_PORTC:
      if(DIO_PinVal == DIO_u8_HIGH)
      {
        SET_BIT(DIO_u8_PORTC_REG,DIO_u8PinId);
      }
      else
      {
        CLR_BIT(DIO_u8_PORTC_REG,DIO_u8PinId);
      }
      break;
    case DIO_u8_PORTD:
      if(DIO_PinVal == DIO_u8_HIGH)
      {
        SET_BIT(DIO_u8_PORTD_REG,DIO_u8PinId);
      }
      else
      {
        CLR_BIT(DIO_u8_PORTD_REG,DIO_u8PinId);
      }
      break;

    }
  }
}

u8 DIO_GetPinVal(u8 Copy_u8PortID, u8 Copy_u8PinId)
{
  u8 Local_u8PinVal ;
  switch(Copy_u8PortID)
  {
  case DIO_u8_PORTA:
    Local_u8PinVal = GET_BIT(DIO_u8_PINA_REG,Copy_u8PinId);
    break;
  case DIO_u8_PORTB:
    Local_u8PinVal = GET_BIT(DIO_u8_PINB_REG,Copy_u8PinId);
    break;
  case DIO_u8_PORTC:
    Local_u8PinVal = GET_BIT(DIO_u8_PINC_REG,Copy_u8PinId);
    break;
  case DIO_u8_PORTD:
    Local_u8PinVal = GET_BIT(DIO_u8_PIND_REG,Copy_u8PinId);
    break;
  }

  return Local_u8PinVal;
}
void DIO_VoidSetPortDirection(u8 DIO_u8PortId, u8 DIO_PortDir)
{
  switch(DIO_u8PortId)
  {
  case DIO_u8_PORTA : DIO_u8_DDRA_REG = DIO_PortDir;break;
  case DIO_u8_PORTB : DIO_u8_DDRB_REG = DIO_PortDir;break;
  case DIO_u8_PORTC : DIO_u8_DDRC_REG = DIO_PortDir;break;
  case DIO_u8_PORTD : DIO_u8_DDRD_REG = DIO_PortDir;break;
  }
}
void DIO_VoidSetPortValue(u8 DIO_u8PortId, u8 DIO_PortVal)
{
  switch(DIO_u8PortId)
    {
    case DIO_u8_PORTA : DIO_u8_PORTA_REG = DIO_PortVal;break;
    case DIO_u8_PORTB : DIO_u8_PORTB_REG = DIO_PortVal;break;
    case DIO_u8_PORTC : DIO_u8_PORTC_REG = DIO_PortVal;break;
    case DIO_u8_PORTD : DIO_u8_PORTD_REG = DIO_PortVal;break;
    }

}
