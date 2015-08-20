#ifndef _SEARCH_TREE_H
#define _SEARCH_TREE_H

#define ElementType int

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty( SearchTree T );
Position Find( ElementType X, SearchTree T );
Position FindMin( SearchTree T );
Position FindMax( SearchTree T );
SearchTree Insert( ElementType X, SearchTree T);
SearchTree Delete( ElementType X, SearchTree T);
SearchTree Delete2( ElementType X, SearchTree T); // 4.13.a
ElementType Retrieve( SearchTree T );

/* 4.28 */
int CountNodes( SearchTree T );
int CountLeaves( SearchTree T );
int CountFull( SearchTree T );

/* 4.29 */
SearchTree MakeRandomTree( SearchTree T, int l, int u );

void Traverse( SearchTree T );
void TraverseInOrder( SearchTree T );
#endif // _SEARCH_TREE_H
