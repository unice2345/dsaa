#include "search_tree.h"
#include <stdio.h>

#define SIZE 13 

int main()
{
	int a[SIZE] = {10, 4, 11, 2, 6, 12, 1, 3, 5, 8, 13, 7, 9};
	int i, j;
	SearchTree T = NULL;

	T = MakeEmpty( T );
	for(i = 0; i < SIZE; i++) {
		T = Insert( a[i], T );
	}
	Traverse( T );
	printf("\n");


	TraverseInOrder( T );
	printf("\n");

	Assign_x( T );
	Assign_y( T, 1 );
	Draw_tree( T );
	for(i = 0; i <= SIZE; i++) {
		for(j = 0; j <= SIZE; j++) {
			if( image[i][j] )
				printf("%2d ", image[i][j]);
			else
				printf("  ");
		}
		printf("\n");
	}	
}
