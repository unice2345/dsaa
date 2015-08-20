#include "search_tree.h"
#include <stdio.h>

int main()
{
	SearchTree T = NULL;

	T = MakeRandomTree( T, 0, 10 );

	Traverse( T );
	printf("\n");

	TraverseInOrder( T );
	printf("\n");

}
