#ifndef _SEARCH_TREE_H
#define _SEARCH_TREE_H

#define ElementType int
#define MAX_N 128

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

/* 4.32 */
void PrintRange( SearchTree T, int l, int u );

/* 4.33 */
void Assign_x( SearchTree T );
void Assign_y( SearchTree T, int depth );
ElementType image[MAX_N][MAX_N];
void Draw_tree( SearchTree T );

void Traverse( SearchTree T );
void TraverseInOrder( SearchTree T );
#endif // _SEARCH_TREE_H
