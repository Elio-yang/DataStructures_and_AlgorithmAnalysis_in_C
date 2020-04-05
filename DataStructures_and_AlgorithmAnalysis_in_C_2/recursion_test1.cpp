/*
computing f(n)=n!+f(n-1) where f(0)=1
*/

#include<stdio.h>
#include<stdlib.h>
int F(int);
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",F(n));
    system("pause");
    return 0;
}
int F(int N){
  return (N==0)?1:((N==1)?2:(N+1)*F(N-1)-N*F(N-2));
}
