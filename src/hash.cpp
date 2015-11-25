#include "hash.h"
#include "cmath"

unsigned long Hash::hashALCH(int number, unsigned char* bytes)
{
	unsigned long value = 0;
	
	for (int i = 0; i < number; i ++)
	{
		value ^= 0x74f9c8c3d74fb987 * (bytes[i] << ((i + 0xb3) % 58)) + (bytes[i] + 0xfe899ba6a9231bbe) << (i % 58);
	}
	
	return value ^ 0xc4f413d3dde98627;
}

unsigned long Hash::getPrime(unsigned long v)
{
	unsigned int n = 0x7FFFFFFF + Hash::getRandom(v) % 0x7FFF0000;
	
	while (true)
	{
		bool prime = true;
		
		for (unsigned int i = 2; i < (int)sqrt(n) + 1; i ++)
		{
			if (n % i == 0)
				prime = false;
		}
		
		if (prime)
			return n;
		n ++;
	}
}

unsigned long Hash::getRandom(unsigned long v)
{
	unsigned int time = Hash::getTime();
	time += v * time + v;
	return Hash::hashALCH(sizeof(unsigned int), (unsigned char*)&time);
}

unsigned int Hash::getTime()
{
	return std::time(0);
}
