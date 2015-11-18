#include "polynomial.h"
#include "hash_quad.h"
#include <stdlib.h>
#include <stdio.h>

Polynomial MakeEmpty()
{
	Polynomial TmpCell;
	TmpCell	= malloc(sizeof(struct Node));
	TmpCell->Next = NULL;
	return TmpCell; 
}

int Insert(int Coefficient, int Exponent, Polynomial Poly, Position P)
{
	if(Poly == NULL || P == NULL || 0 == Coefficient)
		return -1;

	Position TmpCell = malloc(sizeof(struct Node));
	TmpCell->Coefficient = Coefficient;
	TmpCell->Exponent = Exponent;
	
	TmpCell->Next = P->Next;
	P->Next = TmpCell;

	return 0;
}

void Print(Polynomial Poly)
{
	Position P;
	P = Poly->Next;
	while(P != NULL){
//		if (P->Coefficient > 1)
//			printf("%d", P->Coefficient);
//		printf("x");
//		if (P->Exponent > 1)
//			printf("^%d", P->Exponent);

		if (P->Coefficient == 1 && P->Exponent == 0) {
			printf("1");
			goto next;
		}
		if (P->Coefficient > 1)
			printf("%d", P->Coefficient);
		else if (P->Coefficient == 1)
			;
		else // P->Cofficient < 1
			goto next;

		if (P->Exponent == 0) ;
		else if (P->Exponent == 1)
			printf("x");
		else 
			printf("x^%d", P->Exponent);			
next:
		if (P->Next)
			printf(" + ");
		P = P->Next;
	}
	printf("\n");
}

void Delete(Polynomial Poly)
{
	Position P, TmpCell;
	P = Poly;
	while(P != NULL){
		TmpCell = P;
		P = P->Next;
		free(TmpCell);
	}
}

Position Advance(Polynomial Poly, Position P)
{
	if(P != NULL)
		P = P->Next;
	return P;
}

Position Header(Polynomial Poly)
{
	return Poly;
}

Position First(Polynomial Poly)
{
	if(Poly != NULL)
		return Poly->Next;
	else
		return NULL;
}

Polynomial Add(Polynomial Poly1, Polynomial Poly2)
{
	Polynomial Poly = MakeEmpty();
	Position P, P1, P2;
	P = Poly;
	P1 = Poly1->Next;
	P2 = Poly2->Next;

	while(P1 != NULL && P2 != NULL){
		if(P1->Exponent < P2->Exponent){
			Insert(P1->Coefficient, P1->Exponent, Poly, P);
			P1 = P1->Next;
			P = P->Next;
		}else if(P1->Exponent > P2->Exponent){
			Insert(P2->Coefficient, P2->Exponent, Poly, P);
			P2 = P2->Next;
			P = P->Next;
		}else{
			Insert(P1->Coefficient + P2->Coefficient, P2->Exponent, Poly, P);
			P1 = P1->Next;
			P2 = P2->Next;
			P = P->Next;
		}
	}

	while(P1 != NULL){
		Insert(P1->Coefficient, P1->Exponent, Poly, P);
		P = P->Next;
		P1 = P1->Next;
	}

	while(P2 != NULL){
		Insert(P2->Coefficient, P2->Exponent, Poly, P);
		P2 = P2->Next;
		P = P->Next;
	}
	return Poly;
}

/* Add Poly1 to Poly2 */
Polynomial Add2(Polynomial Poly1, Polynomial Poly2)
{
	Position P1, P2, PreP2;
	P1 = Poly1->Next;
	P2 = Poly2->Next;
	PreP2 = Poly2;

	while(P1 != NULL && P2 != NULL){
		if(P1->Exponent < P2->Exponent){
			Insert(P1->Coefficient, P1->Exponent, Poly2, PreP2);
			PreP2 = PreP2->Next;
			P1 = P1->Next;
		}else if(P1->Exponent > P2->Exponent){
			PreP2 = P2;
			P2 = P2->Next;
		}else{
			P2->Coefficient += P1->Coefficient;
			PreP2 = P2;
			P2 = P2->Next;
			P1 = P1->Next;
		}
	}
	
	while(P1 != NULL){
		Insert(P1->Coefficient, P1->Exponent, Poly2, PreP2);
		PreP2 = PreP2->Next;
		P1 = P1->Next;
	}

	return Poly2;
}

int IsEmpty(Polynomial Poly)
{
	return Poly->Next == NULL;
}

Position FindPrevious(int Exponent, Polynomial Poly)
{
	if(IsEmpty(Poly)) return Poly;

	Position PreP, P;

	PreP = Header(Poly);
	P = First(Poly);
	while(P != NULL && P->Exponent < Exponent){
		PreP = P;
		P = P->Next;
	}	

	if(P != NULL && P->Exponent == Exponent)
		PreP = P;

	return PreP;
}

Polynomial Multiply(Polynomial Poly1, Polynomial Poly2)
{
	Polynomial Poly;
	Position P, P1, P2;

	Poly = MakeEmpty();
	P = Poly;
	P1 = Poly1->Next;
	P2 = Poly2->Next;

	while(P1 != NULL){
		P2 = Poly2->Next;
		while(P2 != NULL){
			P = FindPrevious(P1->Exponent + P2->Exponent, Poly);
			if(P == Poly)
				Insert(P1->Coefficient * P2->Coefficient, P1->Exponent + P2->Exponent, Poly, P);
			else if(P->Exponent == P1->Exponent + P2->Exponent)
				P->Coefficient += P1->Coefficient * P2->Coefficient;
			else
				Insert(P1->Coefficient * P2->Coefficient, P1->Exponent + P2->Exponent, Poly, P);
			P2 = P2->Next;
		}
		P1 = P1->Next;
	}

	return Poly;
}

void MultiplyNode(Polynomial Poly, Position P)
{
	Position TmpCell;
	TmpCell = Poly->Next;

	while(TmpCell != NULL){
		TmpCell->Coefficient *= P->Coefficient;
		TmpCell->Exponent += P->Exponent;
		TmpCell = TmpCell->Next;
	}
}

void DivideNode(Polynomial Poly, Position P)
{
	Position TmpCell;
	TmpCell = Poly->Next;

	while(TmpCell != NULL){
		TmpCell->Coefficient /= P->Coefficient;
		TmpCell->Exponent -= P->Exponent;
		TmpCell = TmpCell->Next;
	}
}

Polynomial Multiply2(Polynomial Poly1, Polynomial Poly2)
{
	Polynomial Poly;
	Position P1;

	Poly = MakeEmpty();
	P1 = Poly1->Next;

	while(P1 != NULL){
		MultiplyNode(Poly2, P1);
		Add2(Poly2, Poly);
		DivideNode(Poly2, P1);
		P1 = P1->Next;
	}

	return Poly;
}

Polynomial Sort(Polynomial Poly)
{
	Polynomial Poly2;
	Position P, P2, PreP2;
	int insert;

	Poly2 = MakeEmpty();
	P = Poly->Next;

	while(P != NULL){
		P2 = Poly2->Next;
		PreP2 = Poly2;
		insert = 0;
		while(P2 != NULL){
			if(P->Exponent < P2->Exponent){
				Insert(P->Coefficient, P->Exponent, Poly2, PreP2);
				insert = 1;
				break;
			}else if(P->Exponent == P2->Exponent){
				P2->Coefficient += P->Coefficient;
				insert = 1;
				break;
			}else{
				PreP2 = P2;
				P2 = P2->Next;
			}
		}

		if(!insert){
			Insert(P->Coefficient, P->Exponent, Poly2, PreP2);
		}

		P = P->Next;
	}

	Delete(Poly);
	Poly = Poly2;

	return Poly;
}

Polynomial Multiply3(Polynomial Poly1, Polynomial Poly2)
{
	Polynomial Poly;
	Position P, P1, P2;

	Poly = MakeEmpty();
	P = Poly;
	P1 = Poly1->Next;

	while(P1 != NULL){
		P2 = Poly2->Next;
		while(P2 != NULL){
			Insert(P1->Coefficient * P2->Coefficient, P1->Exponent + P2->Exponent,
					Poly, P);
			P = P->Next;
			P2 = P2->Next;
		}
		P1 = P1->Next;
	}

	Poly = Sort(Poly);
	return Poly;
}

Polynomial Pow(Polynomial Poly, int N)
{
	if(N == 1) return Poly;

	if(N % 2 == 0)
		return Pow(Multiply3(Poly,Poly), N/2);
	else 
		return Multiply3(Pow(Multiply3(Poly,Poly), N/2), Poly);
}

void Multiply4(Polynomial Poly1, Polynomial Poly2, int M, int N)
{
	Position P1, P2;
	HashTable H;
	int max_exponent = 0;

	P1 = First(Poly1);
	P2 = First(Poly2);
	H = InitializeTable( (M*N)*2 + 1 );
	
	while ( P1 != NULL ) {
		P2 = First(Poly2);
		while ( P2 != NULL ) {
			InsertHashTable(P1->Exponent + P2->Exponent,
				P1->Coefficient * P2->Coefficient,
				H );
			if ( max_exponent < P1->Exponent + P2->Exponent )
				max_exponent = P1->Exponent + P2->Exponent; 
			P2 = P2->Next;
		}
		P1 = P1->Next;
	}	

//	printf("max_exponent = %d\n", max_exponent);
	printf("Product is: ");
	PrintHashTable( H, max_exponent );
	
	FreeHashTable(H);
}
