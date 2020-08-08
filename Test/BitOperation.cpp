#include "amain.h"

void print_bits_state(char aCh) 
{
	printf("%i: ", aCh);
	printf("%i: ", (aCh & 0x80) ? 1 : 0);
	printf("%i: ", (aCh & 0x40) ? 1 : 0);
	printf("%i: ", (aCh & 0x20) ? 1 : 0);
	printf("%i: ", (aCh & 0x10) ? 1 : 0);
	printf("%i: ", (aCh & 0x08) ? 1 : 0);
	printf("%i: ", (aCh & 0x04) ? 1 : 0);
	printf("%i: ", (aCh & 0x01) ? 1 : 0);

}


int main(int argc, char* argv[]) 
{



	getchar();
	return 0;
}