#define DIO_INTERFACE_H_

#define DIO_u8_PORTA 0
#define DIO_u8_PORTB 1
#define DIO_u8_PORTC 2
#define DIO_u8_PORTD 3

#define DIO_u8_Pin0 0
#define DIO_u8_Pin1 1
#define DIO_u8_Pin2 2
#define DIO_u8_Pin3 3
#define DIO_u8_Pin4 4
#define DIO_u8_Pin5 5
#define DIO_u8_Pin6 6
#define DIO_u8_Pin7 7

#define DIO_u8_OUTPUT 0xFF
#define DIO_u8_INPUT 0x00

#define DIO_u8_HIGH 1
#define DIO_u8_LOW 0

#define PORT_MAX    4
#define PIN_MAX     8

//functions prototypes

//function to set pin direction
//port
//pin_number
//direction
void Dio_Init();
void DIO_VoidSetPinDirection(u8 DIO_u8PortId, u8 DIO_u8PinId, u8 DIO_PinDir);
void DIO_VoidSetPinValue(u8 DIO_u8PortId, u8 DIO_u8PinId, u8 DIO_PinVal);
void DIO_VoidSetPortDirection(u8 DIO_u8PortId, u8 DIO_PortDir);
void DIO_VoidSetPortValue(u8 DIO_u8PortId, u8 DIO_PortVal);
u8 DIO_GetPinVal(u8 Copy_u8PortID, u8 Copy_u8PinId);
