#include "chat_scene.h"

int* make_page(Avatar *avatar, char *str, Char *charset, uint8_t count)
{
	uint8_t r, cnt;
	int *Page = (int)calloc(128, sizeof(int) * 128);
	for (int i = 0; i < 128; i++)
	{
		if (i < 32)
		{
			*(Page + i) = Read_Memory(avatar->start_adr + i + count * 32);			
		}
		else if (i < 128)
		{
			if (((i - 32) % 6) == 0)
			{
				r = int(*(str + ((int)(i - 32) / 6))) - 97;
				cnt = 0;
			}
			else
			*(Page + i) = Read_Memory(charset[r].start_adr + cnt);		
			cnt++;	
		}
	}
	return Page;
}