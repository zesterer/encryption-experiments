#include "stdio.h"
#include "hash.h"

int main(int argc, char* argv[])
{
	printf("Hello, World!\n");
	
	for (int i = 0; i < 100; i ++)
		printf("%016lX\n", Hash::hashALCH(sizeof(i), (unsigned char*)&i));
	
	printf("Time: %d\n", Hash::getTime());
	
	printf("Prime: %u\n", Hash::getPrime());

	return 0;
}
