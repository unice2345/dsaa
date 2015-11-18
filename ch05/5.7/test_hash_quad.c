#include <stdio.h>
#include "hash_quad.h"

#define TABLESIZE 5

int main()
{
	HashTable H;
	int val[TABLESIZE] = {2, 5, 6, 7, 9};
	int key[TABLESIZE] = {3, 4, 6, 23, 45};
	int i;

	H = InitializeTable(TABLESIZE*2 + 1);

	for(i = 0; i < TABLESIZE; i++) {
		InsertHashTable(key[i], val[i], H);
	}	

	PrintHashTable( H, key[TABLESIZE-1] );
}
