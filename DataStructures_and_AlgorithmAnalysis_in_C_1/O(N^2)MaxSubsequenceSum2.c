#include<stdio.h>
#define MAXN 100000    //本题最大数据是十万
int main()
{
	int N, i;
	int a[MAXN] = { 0 };

	printf("How many numbers are in this array:\n");
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}

	printf("%d", MaxSubsequenceSum(a, N));

	return 0;
}
int MaxSubsequenceSum(int A[], int N)
{
	int MaxSum, ThisSum, i, j;
	MaxSum = 0;
	for (i = 0; i < N; i++)
	{
		ThisSum = 0;
		for (j = i; j < N; j++)
		{
			ThisSum += A[j];

			if (ThisSum > MaxSum)
			{
				MaxSum = ThisSum;
			}
		}
	}
	return MaxSum;
}
/*
Algorithm analysis:O(N^2)
*/