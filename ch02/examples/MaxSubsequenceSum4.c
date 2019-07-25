#include <stdio.h>

int MaxSubsequenceSum(const int a[], int n)
{
	int thisSum = 0;
	int maxSum = 0;
	
	for (int i = 0; i < n; i++) {
		thisSum += a[i];
		
		if (thisSum > maxSum) {
			maxSum = thisSum;
		} else if (thisSum < 0) {
			thisSum = 0;
		} else {
		}
	}
	
	return maxSum;
}

int main()
{
	int a[] = {4, -3, 5, -2, -1, 2, 6, -2};
	int maxSum = MaxSubsequenceSum(a, 8);
	printf("maxSum is %d\n", maxSum);
}
