/*
Given a integer X and a set of integers which were sorted,
A0,A1,...A_N-1, find lower-index i such that A_i=X, if X 
isn't one of them,return i=-1.
*/

#include<stdio.h>
#define MAXN 1000
#define NotFound -1
int main()
{
	int X, k,N;
	int A[MAXN] = { 0 };

	printf("Enter how many elements are in the sorted set :\nN=");
	scanf("%d", &N);
	printf("Enter the set splited by space in order:\n");
	for (k = 0; k <= N - 1; k++)
	{
		scanf("%d", &A[k]);
	}
	//get the sorted set

	printf("The array you entered is:\n");
	printf("A[%d]=[",N);
	for (k = 0; k <= N - 1; k++)
	{
		printf("%4d", A[k]);
	}
	printf("]\n");
	//print the sorted set

	printf("Enter the number you want to find:\n");
	scanf("%d", &X);
	//input the number X you want to find

	printf("%d", BinarySearch(A, X, N));
	//using binarysearch
	return 0;
}
int BinarySearch(int A[], int X, int N)
{
	int Left, Mid, Right;
	//define left-node,right-node and mid-node
	Left = 0, Right = N - 1;
	//initial consition
	while (Left <= Right)//loop condition:left-node is smaller than right
	{
		Mid = (Left + Right) / 2;//get the mid-node,int makes it a integer
		if (A[Mid] < X)
		{
			Left = Mid + 1;
			//if value-mid<X,X should be the right part of mid,so we make left=mid+1 to have a new set
		}
		else if (A[Mid] > X)
		{
			Right = Mid - 1;
			//if value-mid>X,X should be the left part of mid,so we make right=mid-1 to have a new set
		}
		else
		{
			return Mid;//value-mid=X,that's the solution 
		}
			
	}
	return NotFound;//NotFound has been defined as -1
}