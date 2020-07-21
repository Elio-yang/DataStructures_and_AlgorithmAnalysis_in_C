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
	int ThisSum, MaxSum, i;
	ThisSum = MaxSum = 0;
	for (i = 0; i < N; i++)
	{
		ThisSum += A[i];
		if (ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
		}
		else if (ThisSum < 0)
		{
			ThisSum = 0;
		}
	}
	return MaxSum;
}