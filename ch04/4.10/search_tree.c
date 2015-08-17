#include "search_tree.h"
#include <stdlib.h>
#include <stdio.h>

struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};

SearchTree MakeEmpty( SearchTree T )
{
	if( T != NULL ) {
		MakeEmpty( T->Left );
		MakeEmpty( T->Right );
		free( T );
	}
	return NULL;
}

SearchTree Insert( ElementType X, SearchTree T)
{
	if( T != NULL ) {
		if( X < T->Element )
			T->Left = Insert(X, T->Left);
		if( X > T->Element )
			T->Right = Insert(X, T->Right);
		/* if X==T->Element, do nothing */
	} else {
		T = malloc( sizeof( struct TreeNode ) );
		if( T == NULL ) {
			printf("Malloc failed!\n");
			exit(-1);
		}
		T->Element = X;
		T->Left = T->Right = NULL;
	}
	
	return T;
}

Position Find( ElementType X, SearchTree T )
{
	if( T == NULL )
		return NULL;
	if( X < T->Element )
		return Find( X, T->Left );
	else if ( X > T->Element )
		return Find( X, T->Right );
	else // X == T->Element
		return T;
}

Position FindMin( SearchTree T )
{
	if( T == NULL )
		return NULL;
	if( T->Left == NULL )
		return T;
	else
		return FindMin( T->Left );
}

Position FindMax( SearchTree T )
{
	if( T != NULL ) {
		while( T->Right != NULL )
			T = T->Right;
	}
	return T;
}

SearchTree Delete( ElementType X, SearchTree T)
{
	Position TmpCell;

	if( T == NULL )
		return NULL;
	if( X < T->Element )
		T->Left = Delete( X, T->Left );
	else if( X > T->Element )
		T->Right = Delete( X, T->Right );
	else { // X == T->Element
		if( T->Left == NULL && T->Right == NULL ) {
			free( T );
			return NULL;
		} else if( T->Right == NULL ) {
			TmpCell = T->Left;
			free( T );
			return TmpCell;			
		//} else if( T->Left == NULL ) {
		} else {
			TmpCell = FindMin( T->Right );
			if( TmpCell != NULL ) {
				T->Element = TmpCell->Element;
				T->Right = Delete( T->Element, T->Right );
				return T;
			}
		}
	}

	return T;
}

SearchTree Delete2( ElementType X, SearchTree T) // 4.13.a
{
	Position TmpCell;
	
	if( T == NULL )
		return NULL;
	if( X < T->Element )
		T->Left = Delete( X, T->Left );
	else if( X > T->Element )
		T->Right = Delete( X, T->Right );
	else { // X == T->Element
		TmpCell = FindMax( T->Left );
		if( TmpCell != NULL ) {
			T->Element = TmpCell->Element;
			T->Left = Delete( T->Element, T->Left );
		} else {
			TmpCell = T;
			T = T->Right;
			free( TmpCell );
		}
	}

	return T;
}

ElementType Retrieve( SearchTree T )
{
	if( T != NULL )
		return T->Element;
}

void Traverse( SearchTree T )
{
	if( T != NULL ) {
		printf("%d ", T->Element);
		Traverse(T->Left);
		Traverse(T->Right);
	}
}
