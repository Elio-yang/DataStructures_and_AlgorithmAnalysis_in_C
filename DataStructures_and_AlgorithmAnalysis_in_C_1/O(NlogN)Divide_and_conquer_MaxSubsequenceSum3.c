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
	printf("%d", MaxSubsequence(a, N));

	return 0;
}

int Max(int A, int B, int C)
{
	return (A > B) ? ((A > C) ? A : C) : ((B > C) ? B : C);
}
//return the maxium

int DivideAndConquer(int A[], int Left, int Right)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBorderSum;
	int center, i;

	

	if (Left == Right)
	{
		if (A[Left] > 0)
		{
			return A[Left];
		}
		else
			return 0;
	}
	//base case,when there is only one element in the array

	center = (Left + Right) / 2;

	MaxLeftSum = DivideAndConquer(A, Left, center);	//recursive way to get left_max
	MaxRightSum = DivideAndConquer(A, center + 1, Right);//recursive way to get right_max
	//loop the process:divide->left-part,right-part,border;->left-part-left-part,left-part-center...


	MaxLeftBorderSum = 0;
	LeftBorderSum = 0;
	for (i = center; i >= Left; i--)
	{
		LeftBorderSum += A[i];
		if (LeftBorderSum>MaxLeftBorderSum)
		{
			MaxLeftBorderSum = LeftBorderSum;
		}
	}

	MaxRightBorderSum = 0;
	RightBorderSum = 0;
	for (i = center + 1; i <= Right; i++)
	{
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum)
		{
			MaxRightBorderSum = RightBorderSum;
		}
	}

	return Max(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubsequence(int A[], int N)
{
	return DivideAndConquer(A, 0, N - 1);
}

/*
Algoritm Analysis:O(N*logN)
*/