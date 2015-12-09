#include "hash_quad.h"
#include <stdio.h>

#define LEN 16 

int TableSize = 32;
char s[LEN];

int main()
{
	HashTable H;
	int i, num;

	freopen("dictionary.txt", "r", stdin);
	scanf("%d", &num);

	H = InitializeTable( TableSize );
	
	for(i = 0; i < num; i++) {
		scanf("%s", s);
		Insert(s, H);
	}

	PrintHashTable( H );
	
}
