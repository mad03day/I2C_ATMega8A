#include "internal_mem.h"
#include "chat_scene.h"

/*-----------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------*/

uint16_t i, size;

uint8_t a[20] = {0xA8, 0x3F, 0xD3, 0x00, 0x40, 0xA1, 0xC8, 0xDA, 0x02, 0x81, 0x7E, 0xA4, 0xA6, 0xD5, 0x80, 0x8D, 0x14, 0xAF, 0x20, 0x00};

uint8_t logo[8] = {0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80};

/*-----------------------------------------------------------------------------------*/

struct screen
{
	uint8_t title[8];
};

const Avatar ch_1 = {.start_adr = 0x0000, .end_adr = 0x007f, .width = 32};
const Avatar ch_2 = {.start_adr = 0x0080, .end_adr = 0x00ff, .width = 32};



int main(void)
{
	struct screen image[16][4];
	DDRB = 0xFF;
	

	sei();
	//Write_Memory(0x00, 0xAA);
	//I2C_Init();
	
	//I2C_Init();
	
	for (i = 0; i < 20; i++)
	{
		
		
		
		//send_comand(a[i]);
	}
	
	//size = sizeof(logo)/sizeof(logo[0]);
	
	//Clear_OLed();
	
	
	
	while (1)
	{
		//      for (i = 0; i < 512; i++)
		//      {
		//          send_bytes(logo[i]);
		;//      }

		Write_Memory(2, 3);
	}
	
}

/*-----------------------------------------------------------------------------------*/

ISR (TWI_vect)
{
	
}





/*-----------------------------------------------------------------------------------*/