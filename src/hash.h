#ifndef HASH_H
#define HASH_H

#include "stddef.h"
#include "ctime"

struct Hash
{
	//Arbitrary Length Cryptographic Hasher
	static unsigned long hashALCH(int number, unsigned char* bytes);
	static unsigned long getPrime(unsigned long v = 0);
	static unsigned long getRandom(unsigned long v = 0);
	static unsigned int getTime();
};

#endif
