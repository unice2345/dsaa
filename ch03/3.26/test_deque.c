#include "deque.h"
#include <stdio.h>

int main()
{
	int i;
	Deque D;

	// create deque
	D = CreateDeque(128);

	// push items into deque
	for(i = 0; i < 10; i++) {
		Push(i, D);
	}

	PrintDeque(D);

	// pop items from deque
	for(i = 0; i < 5; i++) {
		Pop(D);
	}
	
	PrintDeque(D);

	// inject items into deque
	for(i = 0; i < 5; i++) {
		Inject(i+5, D);
	}
	
	PrintDeque(D);

	// eject items from deque
	for(i = 0; i < 5; i++) {
		Eject(D);
	}
	
	PrintDeque(D);

	// dispose deque
	DisposeDeque(D);

	return 0;
	
}
