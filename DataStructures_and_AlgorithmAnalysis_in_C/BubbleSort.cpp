#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void BubbleSort(int*,int );
int main ()
{
    int n;
    printf("how many numbers are going to be sorted?\n");
    scanf("%d",&n);
    int a[n];
    printf("enter the numbers:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    BubbleSort(a,n);
    for(int i=0;i<10;i++)
        printf("%5d",a[i]); 
    printf("\n");
    system("pause");
    return 0;
}
void BubbleSort(int *a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<(n-1)-i;j++)
            if(a[j]>a[j+1])
            {
                int temp;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
    }
    return;
}