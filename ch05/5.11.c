#include <stdio.h>

#define K 5
#define N 10

char a[N+1];
char p[K+1];

int init_hash(char a[])
{
	int key = 0;
	int i;
	
	for(i = 0; i < K; i++)
		key += a[i];

	return key;
}

int update_hash(char a[], int i, int* key)
{
	*key += a[i];
	*key -= a[i-K];
}

int check(char a[], int i, char p[])
{
	int j;
	
	for(j = 0; j < K; j++) {
		if(a[i+j] != p[j])
			return 0;
	}

	return 1;
}

int sub_string(char a[], char p[])
{
	int i, j, key_a, key_p;

	key_a = init_hash(a);
	key_p = init_hash(p);
	i = K-1;
	do {
		if(key_a == key_p) {
			if(check(a, i-(K-1), p))
				return i-(K-1);
		}
		update_hash(a, ++i, &key_a);
	} while( i < N );

	return -1;
}

int main()
{
	int i, t, T;
	int pos;

	freopen("input.txt", "r", stdin);

	scanf("%d", &T);
	/* Read p */
	scanf("%s", p);
	printf("p is: %s\n", p);

	for(t = 0; t < T; t++) {
		/* Read a */
		scanf("%s", a);
		printf("a is: %s\n", a);

		pos = sub_string(a, p);
		printf("The position is %d\n", pos);
		
	}
}
