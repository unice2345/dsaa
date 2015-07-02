#include "stack.h"
#include <stdio.h>

int main()
{
	Stack S;
	int i, N, X;

	freopen("sample_input.txt", "r", stdin);
	scanf("%d", &N);

	S = CreateStack(1024);
	for(i = 0; i < N; i++) {
		scanf("%d", &X);
		printf("%d ", X);
		Push(X, S);
	}
	printf("\n");

	while(!IsEmpty(S)) {
		printf("Top = %d, Min = %d\n", Top(S), FindMin(S));
		Pop(S);
	}
	printf("\n");

}




