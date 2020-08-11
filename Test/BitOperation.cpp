#include "amain.h"

void print_bits_state(char aCh) 
{
	printf("%i: ", (unsigned char)aCh);
	printf("%i", (aCh & 0x80) ? 1 : 0);
	printf("%i", (aCh & 0x40) ? 1 : 0);
	printf("%i", (aCh & 0x20) ? 1 : 0);
	printf("%i", (aCh & 0x10) ? 1 : 0);
	printf("%i", (aCh & 0x08) ? 1 : 0);
	printf("%i", (aCh & 0x04) ? 1 : 0);
	printf("%i", (aCh & 0x01) ? 1 : 0);

}

void print_what_endianness() 
{
	short int a, b = 0;

	uint32_t test = 0x11223344;
	uint8_t i;
	uint8_t* ptr = (uint8_t*)&test;

	a = *ptr;
	for (size_t i = 0; i < 4; i++)
	{
		if (i == 4)b = *ptr;

		printf("%u: %X\n", i, *ptr);
		ptr++;
	}
	
	if (a < b) printf("Big-Endian\n");
	else printf("Little-Endian\n");
}

int main(int argc, char* argv[]) 
{
	

	print_bits_state(203);
	print_what_endianness();
	/*
	*  1 & 1 = 1  +
	*  1 & 0 = 0
	*  0 & 1 = 0
	*  0 & 0 = 0
	* 
	*  1 | 1 = 1  *
	*  1 | 0 = 1  
	*  0 | 1 = 1  
	*  0 | 0 = 0
	*/

	getchar();
	return 0;
}