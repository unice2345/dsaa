#include "search_tree.h"
#include <stdio.h>

#define SIZE 7

int main()
{
	//int a[10] = {3, 1, 4, 6, 9, 2, 5, 7};
	int a[SIZE] = {6, 2, 8, 1, 5, 3, 4};
	int i;
	int X = 2;
	SearchTree T = NULL;

	T = MakeEmpty( T );
	for(i = 0; i < SIZE; i++) {
		T = Insert( a[i], T );
	}
	Traverse( T );
	printf("\n");

	T = Delete( X, T );	
	Traverse( T );
	printf("\n");

	printf("Max value = %d\n", Retrieve( FindMax( T ) ) );
	
	T = Find( 5, T );
	if( T )
		printf("5 is found\n");
	else
		printf("5 is not found\n");
}
