/*
给定K个整数组成的序列{ N​1​​, N​2​​, ..., N​K​​  }，“连续子列”被定义为{ N​i​​, N​i + 1​​, ..., N​j​​ }，
其中 1≤i≤j≤K。“最大子列和”则被定义为所有连续子列元素的和中最大者。
例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续子列{ 11, -4, 13 }有最大的和20。
现要求你编写程序，计算给定整数序列的最大子列和。
*/

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
	int ThisSum, MaxSum, i, j, k;
	MaxSum = 0;
	for (i = 0; i < N; i++)//the left node is i
	{
		for (j = i; j < N; j++)//then right node is j
		{
			ThisSum = 0;//before each loop,set maxsum=0

			for (k = i; k <= j; k++)//all subsequence between i and j
			{
				ThisSum += A[k];//sum from A[i]~A[j]
			}
			if (ThisSum > MaxSum)//if thissum is bigger than 0, than set maxsum=thissum
			{
				MaxSum = ThisSum;
			}
		}
	}
	return MaxSum;
}
/*
Algorithm analysis:O(N^3)
*/