/*
ŷ������㷨�����������������������Gcd)�ķ���

�������������Լ���������н�С���Ǹ���������������������Լ����
���Լ����Greatest Common Divisor����дΪGCD��
gcd(a,b) = gcd(b,a mod b) (������a>b ��r=a mod b ,r��Ϊ0)
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