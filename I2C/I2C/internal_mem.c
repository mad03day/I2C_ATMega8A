#include "internal_mem.h"

void Write_Memory (short int adr, uint8_t znach)		// From DataSheet [21]
{
	while(EECR & (1<<EEWE))
	;
	/* Set up address and data registers */
	EEAR = adr;
	EEDR = znach;
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	/* Start eeprom write by setting EEWE */
	EECR |= (1<<EEWE);
}

uint8_t Read_Memory (short int adr)						// From DataSheet [22]
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))
	;
	/* Set up address register */
	EEAR = adr;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}