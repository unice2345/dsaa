#ifndef _HASH_QUAD_H
#define _HASH_QUAD_H

#define ElementType int

struct HashTbl;
typedef struct HashTbl *HashTable;
typedef unsigned int HashTablePosition;

HashTable InitializeTable( int TableSize );
HashTablePosition Find(ElementType Key, HashTable H);
void InsertHashTable(ElementType Key, ElementType Val, HashTable H);
void FreeHashTable(HashTable H);

void PrintHashTable(HashTable H, int MaxVal);
#endif //_HASH_QUAD_H
