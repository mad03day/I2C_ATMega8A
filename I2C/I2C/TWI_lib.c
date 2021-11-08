#include "TWI_lib.h"

/*-----------------------------------------------------------------------------------*/

void I2C_Init(void)
{
	TWBR = TWBR_VALUE;	
}

/*-----------------------------------------------------------------------------------*/

void I2C_Start(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN)|(1<<TWIE);
	while (!(TWCR & (1<<TWINT)))
	;
}

/*-----------------------------------------------------------------------------------*/

void I2C_Write(uint8_t data)
{
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)))
	;
}

/*-----------------------------------------------------------------------------------*/

void I2C_Stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

/*-----------------------------------------------------------------------------------*/

void send_comand(uint8_t data)
{
	I2C_Start();
	
	if (TWSR == 0x08)
	I2C_Write(I2C_Adr_Write_OLed);
	
	if (TWSR == 0x18)
	I2C_Write(comand_byte);
	
	if (TWSR == 0x28)
	I2C_Write(data);
	
	I2C_Stop();
}

/*-----------------------------------------------------------------------------------*/

void send_bytes(uint8_t data)
{
	I2C_Start();
	
	if (TWSR == 0x08)
	I2C_Write(I2C_Adr_Write_OLed);
	
	if (TWSR == 0x18)
	I2C_Write(bytes_byte);
	
	if (TWSR == 0x28)
	I2C_Write(data);
	
	I2C_Stop();
}

/*-----------------------------------------------------------------------------------*/

void Clear_OLed (void)
{
	for (int i = 0; i < 512; i++)
	{
		send_bytes(0x00);
	}
}

/*-----------------------------------------------------------------------------------*/