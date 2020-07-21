#include<stdio.h>
#include"EA.h"
int main()
{
	int Rel = 0;
	long long Tot = 0;
	int i, j;
	long long  N;
	scanf("%lld", &N);
	for (i = 1; i <= N; i++)
	{

		for (j = i + 1; j <= N; j++)
		{
			Tot++;
			if (Gcd(i, j) == 1)
			{
				Rel++;
			}
		}
	}
	printf("The Percentage of relatively prime pairs if %f\n", (double)Rel / Tot);
	return 0;
}