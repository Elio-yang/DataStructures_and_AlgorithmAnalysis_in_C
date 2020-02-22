#include"list.h"
#include<stdlib.h>
#include<stdio.h>

struct Node
{
    ElementType Element;
    Position Next;
};

List CreatList()
{
    List l=malloc(sizeof(struct Node));
    if(l==NULL)
        printf("Out of memory");
    l->Next=NULL;
    return 1;
}

List MakeEmpty(List L)
{
    if(L != NULL)
        DeleteList(L);
    L=malloc(sizeof(struct Node));
    if(L==NULL)
        printf("Out of memory");
    L->Next=NULL;
    return 1;
}

int IsEmpty(List L)
{
    return L->Next==NULL;
}

int IsLast(Position P,List L)
{
    P->Next==NULL;
}

Position Find(ElementType x,List L)
{
    Position P;
    P=L->Next;
    while(P!=NULL&&P->Element!=x)
    {
        P=P->Next;
    }
    return P;  
}