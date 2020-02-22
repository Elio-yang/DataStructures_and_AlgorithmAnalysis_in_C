#include <stdio.h>
int main()
{
	int count=0;
	int n;
	scanf("%d", &n);//n是指数
	while (n != 1)
	{
		if (n % 2 != 0)//奇数
		{
			n -= 1; count++;
		}
		else//偶数 
		{
			n /= 2; count++;
		}
	}

	printf("%d\n", count);

	return 0;
}
			
/*Algorithm Analysis: O(logN)*/
