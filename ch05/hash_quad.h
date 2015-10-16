#ifndef _HASH_QUAD_H
#define _HASH_QUAD_H

#define ElementType int

struct HashTbl;
typedef struct HashTbl *HashTable;
typedef unsigned int Position;

HashTable InitializeTable( int TableSize );
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);

void PrintHashTable(HashTable H);
#endif //_HASH_QUAD_H
