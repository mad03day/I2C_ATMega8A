#define F_CPU 8000000UL
#define F_I2C 400000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define TWBR_VALUE (((F_CPU)/(F_I2C)-16)/2)

#if ((TWBR_VALUE > 255) || (TWBR_VALUE == 0))
#error "TWBR value is not correct"
#endif

#define I2C_Adr_Write_EEPROM 0b10101110
#define I2C_Adr_Read_EEPROM 0b10101111
#define I2C_Adr_Write_OLed 0b01111000
#define I2C_Adr_Data_EEPROM 0xA1
#define I2C_Data_EEPROM 0xB2
#define comand_byte 0b10000000
#define bytes_byte 0b01000000

#define TWI_LIB_H
#ifdef TWI_LIB_H

void I2C_Init(void);
void I2C_Start(void);
void I2C_Write(uint8_t data);
void I2C_Stop(void);
void send_comand(uint8_t data);
void send_bytes(uint8_t data);
void Clear_OLed (void);

#endif