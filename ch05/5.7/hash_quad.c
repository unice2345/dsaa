#include "hash_quad.h"
#include <stdio.h>
#include <malloc.h>

static int IsPrime(int n)
{
	int i;
	for(i = 2; i <= n/2; i++) {
		if (n % i == 0)
			return 0;
	}

	return 1;
}

static int NextPrime(int n)
{
	while(!IsPrime(n))
		n++;

	return n;
}


int Hash(int X, int TableSize)
{
	return X % TableSize;
}

enum KindOfEntry { Legitimate, Empty, Deleted };

struct HashEntry 
{
	ElementType Key;
	ElementType Val;
	enum KindOfEntry Info;
};

struct HashTbl
{
	int TableSize;
	struct HashEntry *Cells;
};


HashTable InitializeTable( int TableSize )
{
	HashTable H;
	int i;

	H = (HashTable) malloc ( sizeof(struct HashTbl) );
	if( !H ) {
		fprintf(stderr, "Alloc HashTable failed.\n");
		return NULL;
	}

	H->TableSize = NextPrime(TableSize);
	H->Cells = (struct HashEntry*) malloc ( sizeof(struct HashEntry) * H->TableSize );
	if( !H->Cells ) {
		fprintf(stderr, "Alloc HashTable cells failed.\n");
		free(H);
		return NULL;
	}
	
	for(i = 0; i < H->TableSize; i++) {
		H->Cells[i].Info = Empty;
		H->Cells[i].Key = 0;
		H->Cells[i].Val = 0;
	}	

//	printf("H->TableSize = %d\n", H->TableSize);
	return H;
}

HashTablePosition Find(ElementType Key, HashTable H)
{
	HashTablePosition P;
	int CollisionNum;

	CollisionNum = 0;	
	P = Hash( Key, H->TableSize );
	while( H->Cells[P].Info != Empty &&
		H->Cells[P].Key != Key ) {
		P += 2*++CollisionNum - 1;
		if( P >= H->TableSize )
			P -= H->TableSize;
	} 
	
	return P;
}

void InsertHashTable(ElementType Key, ElementType Val, HashTable H)
{
	HashTablePosition P;

	P = Find(Key, H);
//	printf("Find key %d at pos %d\n", Key, P);
	if( H->Cells[P].Info == Empty ) {
		H->Cells[P].Info = Legitimate;
		H->Cells[P].Key = Key; 
		H->Cells[P].Val = Val; 
	} else if ( H->Cells[P].Info == Legitimate ) {
		H->Cells[P].Val += Val; 
	}
}

void FreeHashTable(HashTable H)
{
	if(H == NULL)
		return;

	free(H->Cells);
	free(H);
	H = NULL;
}

void PrintHashTable(HashTable H, int MaxVal)
{
	int key, first;
	HashTablePosition Pos;
//	printf("PrintHashTable: \n");
	first = 1;
	for(key = 0; key <= MaxVal; key++) {
		Pos = Find(key, H);
//		printf("Find key %d at pos %d\n", key, Pos);
		if(H->Cells[Pos].Info == Legitimate) {
			if(!first)
				printf("+ ");
//			printf("%dx^%d ", H->Cells[Pos].Val, key);
			if(H->Cells[Pos].Val > 1)
				printf("%d", H->Cells[Pos].Val);
			if(key > 1)
				printf("x^%d", key);
			else if(key == 1)
				printf("x");
			printf(" ");
			first = 0;
		}
	}
	printf("\n");	
}
