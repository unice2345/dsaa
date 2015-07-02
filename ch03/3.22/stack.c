#include "stack.h"
#include <malloc.h>
#include <stdio.h>

#define EmptyTOS -1

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	int TopOfMStack;
	ElementType* Array;
	ElementType* MArray;
};


Stack CreateStack(int MaxElements)
{
	Stack S;

	S = (Stack) malloc (sizeof(struct StackRecord));
	if(S == 0) {
		printf("No memory for stack!\n");
		return 0;
	}

	S->Array = (ElementType*) malloc (sizeof(ElementType)*MaxElements);
	if(S->Array == 0) {
		printf("No memory for stack array\n");
		free(S);
		return 0;
	}

	S->MArray = (ElementType*) malloc (sizeof(ElementType)*MaxElements);
	if(S->MArray == 0) {
		printf("No memory for stack min array\n");
		free(S->Array);
		free(S);
		return 0;
	}

	S->TopOfStack = EmptyTOS;
	S->TopOfMStack = EmptyTOS;
	S->Capacity = MaxElements;

	return S;
}

int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}

void Push(ElementType X, Stack S)
{
	if(S->TopOfStack >= S->Capacity) {
		printf("Stack overflow!\n");
		return;
	}

	S->Array[++S->TopOfStack] = X;
	if(S->TopOfMStack == EmptyTOS || X < S->MArray[S->TopOfMStack]) {
		S->MArray[++S->TopOfMStack] = X;
	}
}

ElementType Top(Stack S)
{
	if(S->TopOfStack < 0) {
		printf("Stack is empty!\n");
		return 0;
	}

	return S->Array[S->TopOfStack];
}

ElementType FindMin(Stack S)
{
	if(S->TopOfMStack < 0) {
		printf("MStack is empty!\n");
		return 0;
	}

	return S->MArray[S->TopOfMStack];
}

void Pop(Stack S)
{
	if(S->TopOfStack >= 0) {
		if(S->MArray[S->TopOfMStack] == S->Array[S->TopOfStack])
			S->TopOfMStack--;
		S->TopOfStack--;

	}
}
