#ifndef _STACK_H
#define _STACK_H

//#define ElementType int
typedef int ElementType;
struct StackRecord;
typedef struct StackRecord* Stack;

Stack CreateStack(int MaxElements);

int IsEmpty(Stack S);

void Push(ElementType X, Stack S);
ElementType Top(Stack S);
ElementType FindMin(Stack S);
void Pop(Stack S);

#endif //_STACK_H

