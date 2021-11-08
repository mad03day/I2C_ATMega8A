#include "internal_mem.h"

#define CHAT_SCENE_H
#ifdef CHAT_SCENE_H

typedef struct {
	uint16_t start_adr;
	uint16_t end_adr;
	uint8_t width;
} Avatar;

typedef struct {
	uint16_t start_adr;
	uint16_t end_adr;
	uint8_t width;
} Char;


#endif