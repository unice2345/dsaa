#include "hash_linear.h"
#include <stdio.h>

#define LEN 7

int a[LEN] = {4371, 1323, 6173, 4199, 4344, 9679, 1989};
int TableSize = 10;

int main()
{
	HashTable H;
	int i;

	H = InitializeTable( TableSize );
	
	for(i = 0; i < LEN; i++) {
		Insert(a[i], H);
	}

	PrintHashTable( H );
}
