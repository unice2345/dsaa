#include "hash_quad.h"
#include <stdio.h>
#include <malloc.h>

int Hash(int X, int TableSize)
{
	return X % TableSize;
}

enum KindOfEntry { Legitimate, Empty, Deleted };

struct HashEntry 
{
	ElementType Element;
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

	H->TableSize = TableSize;
	H->Cells = (struct HashEntry*) malloc ( sizeof(struct HashEntry) * TableSize );
	if( !H->Cells ) {
		fprintf(stderr, "Alloc HashTable cells failed.\n");
		free(H);
		return NULL;
	}
	
	for(i = 0; i < TableSize; i++) {
		H->Cells[i].Info = Empty;
	}	

	return H;
}

Position Find(ElementType Key, HashTable H)
{
	Position P;
	int CollisionNum;

	CollisionNum = 0;	
	P = Hash( Key, H->TableSize );
	while( H->Cells[P].Info != Empty &&
		H->Cells[P].Element != Key ) {
		P += 2*++CollisionNum - 1;
		if( P >= H->TableSize )
			P -= H->TableSize;
	} 
	
	return P;
}

void Insert(ElementType Key, HashTable H)
{
	Position P;

	P = Find(Key, H);
	if( H->Cells[P].Info == Empty ) {
		H->Cells[P].Info = Legitimate;
		H->Cells[P].Element = Key; 
	}
}

HashTable Rehash(HashTable H)
{
	int i;
	int TableSize;
	struct HashEntry* Cells;

	TableSize = H->TableSize;
	Cells = H->Cells;

	free( H );
	H = InitializeTable( TableSize * 2 );	
	
	for(i = 0; i < TableSize; i++) {
		if(Cells[i].Info == Legitimate) {
			Insert(Cells[i].Element, H);
		}
	}	

	free( Cells );

	return H;
}

void PrintHashTable(HashTable H)
{
	int i;
	printf("Key	 Element\n");
	for(i = 0; i < H->TableSize; i++) {
		printf("%d	", i);
		if(H->Cells[i].Info == Legitimate)
			printf("%d\n", H->Cells[i].Element);
		else
			printf(" \n");
	}
}
