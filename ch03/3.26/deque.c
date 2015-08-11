#include "deque.h"
#include <malloc.h>
#include <stdio.h>

typedef struct QueueRecord {
	int capacity;
	int head;
	int tail;
	int size;
	ElementType *array;
}QueueRecord ;

int IsEmpty(Deque D)
{
	return D->size == 0;
}

int IsFull(Deque D)
{
	return D->size == D->capacity;
}

Deque CreateDeque(int MaxElements)
{
	Deque D;	
	D = malloc(sizeof(QueueRecord));
	if( D == NULL ) {
		printf("Allocate failed!\n");
		return NULL;
	}

	D->array = malloc(sizeof(ElementType) * MaxElements);
	if( D->array == NULL ) {
		printf("Allocate failed!\n");
		return NULL;
	}

	D->capacity = MaxElements; 
	D->size = 0;
	D->head = 1;
	D->tail = 0;

	return D;
}

static int Succ(int tail, int capacity)
{
	if(++tail == capacity)
		tail = 0;
	return tail;
}

static int Prec(int head, int capacity)
{
	if(--head == -1)
		head = capacity-1;
	return head;
}

void DisposeDeque(Deque D)
{
	if( D->array )
		free(D->array);
	free(D);	
}

void Push(ElementType X, Deque D) // Insert X on the front of Deque 
{
	if( IsFull(D) )
		return;

	D->head = Prec(D->head, D->capacity);
	D->array[D->head] = X;
	D->size ++;
}

void PrintDeque(Deque D)
{
	int head = D->head;
	int tail = D->tail;

	while(head != tail) {
		printf("%d ", D->array[head]);
		head = Succ(head, D->capacity);
	}
	printf("%d\n", D->array[head]);
}

void Pop(Deque D) // Remove X from the front of Deque 
{
	if( IsEmpty(D) )
		return;

	D->head = Succ(D->head, D->capacity);
	D->size --;
}

void Inject(ElementType X, Deque D) // Insert X on the rear of Deque
{
	if( IsFull(D) )
		return;

	D->tail = Succ(D->tail, D->capacity);
	D->array[D->tail] = X;
	D->size ++; 
}

void Eject(Deque D) // Remove X from the rear of Deque
{
	if( IsEmpty(D) )
		return;
	
	D->tail = Prec(D->tail, D->capacity);
	D->size --;
 }
