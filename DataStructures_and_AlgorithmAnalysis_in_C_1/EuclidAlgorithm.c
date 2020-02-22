/*
欧几里得算法：计算两个数的最大公因数（Gcd)的方法

两个整数的最大公约数等于其中较小的那个数和两数相除余数的最大公约数。
最大公约数（Greatest Common Divisor）缩写为GCD。
gcd(a,b) = gcd(b,a mod b) (不妨设a>b 且r=a mod b ,r不为0)
a=nb+r

*/
#include<stdio.h>
int main()
{
	unsigned int M, N;

	printf("Please enter two numbers:\n");
	scanf("%d %d", &M, &N);
	Gcd(M, N);
	return 0;
}
int Gcd(unsigned int M, unsigned int N)
{
	unsigned int Rem;
	while (N > 0)
	{
		Rem = M % N;
		M = N;
		N = Rem;
	}
	printf("%d", M);
	return M;
}