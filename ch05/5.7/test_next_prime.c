#include <stdio.h>

static int IsPrime(int n)
{
	int i;
	for(i = 2; i <= n/2; i++) {
		if (n % i == 0)
			return 0;
	}

	return 1;
}

static int NextPrime(int n)
{
	while(!IsPrime(n))
		n++;

	return n;
}

int main()
{
	int n, next_prime;

	printf("Input number: ");
	scanf("%d", &n);
	
	next_prime = NextPrime(n);
	printf("Next prime of %d is %d\n",
			n, next_prime);
}
