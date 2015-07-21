#include "queue.h"
#include <malloc.h>

typedef struct QueueRecord {
	int capacity;
	int front;
	int rear;
	int size;
	ElementType *array;
}QueueRecord ;

int IsEmpty(Queue Q)
{
	return Q->size == 0;
}

int IsFull(Queue q)
{
	return q->size == q->capacity;
}

Queue CreateQueue(int MaxElements)
{
	Queue q;
	q = malloc(sizeof(QueueRecord));
	if( q == NULL ) {
		printf("Allocate failed!\n");
		return NULL;
	}

	q->array = malloc(sizeof(ElementType) * MaxElements);
	if( q->array == NULL ) {
		printf("Allocate failed!\n");
		return NULL;
	}

	q->capacity = MaxElements;
	q->size = 0;
	q->front = 0;
	q->rear = -1;
}

static int Succ(int rear, int capacity)
{
	if(++rear == capacity)
		rear = 0;
	return rear;
}

void Enqueue(ElementType X, Queue Q)
{
	if( IsFull(Q) )
		return;
	Q->rear = Succ(Q->rear, Q->capacity);
	Q->array[Q->rear] = X;
	Q->size ++;		

}

ElementType Front(Queue Q)
{
	return Q->array[Q->front];
}

void Dequeue(Queue Q)
{
	if( !IsEmpty(Q) ) {
		Q->front = Succ(Q->front, Q->capacity);
		Q->size --;
	}
	
}

ElementType FrontAndDequeue(Queue Q)
{
	ElementType x;

	x = Front(Q);
	Dequeue(Q);

	return x;
}

void DisposeQueue(Queue Q)
{
	if( Q->array )
		free(Q->array);
	free(Q);	
}
