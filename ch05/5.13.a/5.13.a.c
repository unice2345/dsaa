#include "hash_quad.h"
#include <stdio.h>

#define LEN 16 
int TableSize = 32;
char s[LEN];

char a[LEN];
char m[LEN][LEN] = {"this", "wats", "oahg", "fgdt"};

int main()
{
	int row = 4;
	int col = 4;
	int max_len;
	int dirct;
	int size;
	int x, y;
	HashTable H;
	int i, num;

	/* Construct dictionary */
	freopen("dictionary.txt", "r", stdin);
	scanf("%d", &num);

	H = InitializeTable( TableSize );
	
	for(i = 0; i < num; i++) {
		scanf("%s", s);
		Insert(s, H);
	}


	/* Read data */
	max_len = row > col ? row : col;
	//for(y = 0; y < row; y++) {
	//	printf("%s\n", m[y]);
	//}	

	/* */
	for(y = 0; y < row; y++) {
		for(x = 0; x < col; x++) {
			for(dirct = 0; dirct < 8; dirct++) {
				for(size = 0; size < max_len; size++) {
					switch(dirct) {
					case 0:
						if(x+size < col)
							a[size] = m[y][x+size];
						else
							goto finish;
						break;
					case 1:
						if(x+size < col && y+size < row)
							a[size] = m[y+size][x+size];
						else
							goto finish;
						break;
					case 2:
						if(y+size < row)
							a[size] = m[y+size][x];
						else
							goto finish;
						break;	
					case 3:
						if(x-size >= 0 && y+size < row)
							a[size] = m[y+size][x-size];
						else
							goto finish;
						break;	
					case 4:
						if(x-size >= 0)
							a[size] = m[y][x-size];
						else
							goto finish;
						break;	
					case 5:
						if(x-size >= 0 && y-size >= 0)
							a[size] = m[y-size][x-size];
						else
							goto finish;
						break;	
					case 6:
						if(y-size >= 0)
							a[size] = m[y-size][x];
						else
							goto finish;
						break;	
					case 7:
						if(x+size < col && y-size >= 0)
							a[size] = m[y-size][x+size];
						else
							goto finish;
						break;	
					default:
						break;		
					}

					if(size + 1 >= max_len) {
						size++;
						goto finish;
					}
					continue;
finish:
					a[size] = '\0';
					if(CheckInTable(a, H)) {
						printf("(%d, %d) dirct = %d, size = %d: ",
							 y, x, dirct, size);
						printf("%s\n", a);
					}
					break; // break from for
				}
			}
		}
	}	
	
}

