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

void Traverse( SearchTree T );
#endif // _SEARCH_TREE_H
