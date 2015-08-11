#ifndef _DEQUE_H
#define _DEQUE_H

#define ElementType int
struct QueueRecord;
typedef struct QueueRecord *Deque;

int IsEmpty(Deque D);
int IsFull(Deque D);
Deque CreateDeque(int MaxElement);
void DisposeDeque(Deque D);

void Push(ElementType X, Deque D); // Insert X on the front of Deque 
void Pop(Deque D); // Remove X from the front of Deque 
void Inject(ElementType X, Deque D); // Insert X on the rear of Deque
void Eject(Deque D); // Remove X from the rear of Deque

void PrintDeque(Deque D);
#endif // _DEQUE_H
