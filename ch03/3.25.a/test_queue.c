#include "queue.h"
#include <stdio.h>

int main()
{
	int i;
	Queue q;

	q = CreateQueue(128);
	for(i = 0; i < 10; i++) {
		Enqueue(i, q);
	}

	while( !IsEmpty(q) ) {
		printf("%d ", FrontAndDequeue(q) );
	}

	DisposeQueue(q);

	return 0;
	
}
