#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H

typedef struct Node* PtrToNode;

struct Node
{
	int Coefficient;
	int Exponent;
	PtrToNode Next;
};

typedef PtrToNode Polynomial;
typedef PtrToNode Position;

Polynomial MakeEmpty();
int Insert(int Coefficient, int Exponent, Polynomial Poly, Position P);
void Print(Polynomial Poly);
void Delete(Polynomial Poly);
Position Advance(Polynomial Poly, Position P);
Position Header(Polynomial Poly);
Position First(Polynomial Poly);
int IsEmpty(Polynomial Poly);

/* 3.6 */
Polynomial Add(Polynomial Poly1, Polynomial Poly2);
Polynomial Add2(Polynomial Poly1, Polynomial Poly2);
/* 3.7 */
Position FindPrevious(int Exponent, Polynomial Poly);
Polynomial Multiply(Polynomial Poly1, Polynomial Poly2);
void MultiplyNode(Polynomial Poly, Position P);
void DivideNode(Polynomial Poly, Position P);
/* 3.7 (b) */
Polynomial Multiply2(Polynomial Poly1, Polynomial Poly2);
/* 3.7 (c) */
Polynomial Sort(Polynomial Poly);
Polynomial Multiply3(Polynomial Poly1, Polynomial Poly2);
/* 3.8 */
Polynomial Pow(Polynomial Poly, int N);

/* 5.7 */
void Multiply4(Polynomial Poly1, Polynomial Poly2, int M, int N);
#endif 
