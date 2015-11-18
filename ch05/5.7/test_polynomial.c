#include "polynomial.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
	int i, exponent, cofficient, ret_val;
	Polynomial Poly1, Poly2; 
	Position P1, P2;
	int M, N;
	M = 3;
	N = 2;
	
	Poly1 = MakeEmpty();
	Poly2 = MakeEmpty();
	P1 = Header(Poly1);
	P2 = Header(Poly2);
	srand(time(NULL));
	for(i = 1; i <= M; i++){
		exponent = rand() % 10;
		cofficient = rand() % 10;
//		printf("poly1 c,e = %d,%d\n", cofficient, exponent);
		ret_val = Insert(cofficient, exponent, Poly1, P1);
		if(0 == ret_val)
			P1 = Advance(Poly1, P1);
		
	}

	for(i = 1; i <= N; i++){
		exponent = rand() % 10;
		cofficient = rand() % 10;
//		printf("poly2 c,e = %d,%d\n", cofficient, exponent);
		ret_val = Insert(cofficient, exponent, Poly2, P2);
		if(0 == ret_val)
			P2 = Advance(Poly2, P2);
		
	}
	
	printf("Poly1 is: ");
	Print(Poly1);
	printf("Poly2 is: ");
	Print(Poly2);

	Multiply4(Poly1, Poly2, M, N);

	Delete(Poly1);
	Delete(Poly2);
	return 0;
}
