#include <stdio.h>

#define MAX_N 1024
#define INFINITY 1000000000
//#define DEBUG

typedef struct node {
	int pi;
	int visit;
	int d;
}node_t;

node_t a[MAX_N];
int map[MAX_N][MAX_N];
int q[MAX_N];
int N, E;

int IsEmpty()
{
	int i;
	for(i = 0; i < N; i++) {
		if(q[i])
			return 0;
	}
	return 1;
}

int FindMinOut()
{
	int i, j, min_index, min_d;
	/* find first value */
	for(i = 0; i < N; i++) {
		if(q[i]){
			j = i;
			min_index = i;
			min_d = a[i].d;
			break;
		}
	}

	/* find min out */
	for(j = i+1; j < N; j++) {
		if(q[j] && a[j].d < min_d) {
			min_index = j;
			min_d = a[j].d;
		}
	}

	q[min_index] = 0;
	return min_index;
} 

void Enqueue(int i)
{
	q[i] = 1;
}

void Dijkstra()
{
	node_t u, v;
	int i, j;
	while( !IsEmpty() ) {
		i = FindMinOut();
#ifdef DEBUG
		printf("%c %d \n", i+'A', a[i].d);
#endif // DEBUG
		for(j = 0; j < N; j++) {
			if( j != i && map[i][j] && 
			a[j].d > a[i].d + map[i][j] ) {
				a[j].d = a[i].d + map[i][j];
				if( !a[j].visit ) {
					a[j].visit = 1;
					a[j].pi = i;
					Enqueue(j);
#ifdef DEBUG
		printf("  %c %d \n", j+'A', a[j].d);
#endif // DEBUG
				}
				
			}
		}
	}
}

void Print_path(int i)
{
	if(a[i].pi == -1) {
		printf(" %c ", i + 'A');	
		return;
	}
	Print_path(a[i].pi);
//	printf("%d ", i);	
	printf(" %c ", i + 'A');	
}

int main()
{
	int i, j, k, c;
	int start;

	/* Read data */
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &E);
	for(k = 0; k < E; k++) {
		scanf("%d %d %d", &i, &j, &c);
		map[i][j] = c;
	}

#ifdef DEBUG
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
#endif // DEBUG	
	/* Init */
	for(i = 0; i < N; i++) {
		a[i].pi = -1;
		a[i].visit = 0;
		a[i].d = INFINITY;
	}
	start = 0;
	a[start].pi = -1;
	a[start].visit = 1;
	a[start].d = 0;
	Enqueue(start);

	/**/
	Dijkstra();

	/* Print path */
	for(i = 0; i < N; i++) {
		printf("Path for %c:", i+'A');
		Print_path(i);
		printf("\n");
	}
}
