#include<stdlib.h>
#include<stdio.h>

typedef int ElementType;//数据域的元素类型
typedef struct Node Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List CreatList();//建表
Position NewNode(ElementType x);//新建节点
List MakeEmpty(List L);//做空
ElementType IsEmpty(List L);//判断为空
ElementType IsLast(Position P, List L);//是否最后一个元素
Position Find(ElementType x,List L); //查找
void Delete(ElementType x,List L);//删除元素
Position FindPrevious(ElementType x,List L);//找前驱
void Insert(ElementType x,List L,Position P);//插入
void DeleteList(List L);//删除表
void PrintList(List L);

Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

struct Node
{
    ElementType Element;//数据域
    Position Next;//指针域(指向struct的指针)
};

//主函数
int main(int argc, char const*argv[])
{
    List L=CreatList();//创建了表头
    /*
    相关操作
    */
    system("pause");
    return 0;
}


List CreatList()//表头
{
    List L=(List)malloc(sizeof(Node));
    if(L==NULL)
    {
         printf("Out of memory");
        exit(1);
    }
    L->Next=NULL;
    return L;
}

Position NewNode(ElementType x)//新建节点
{
   Position newNode=(Position)malloc(sizeof(Node));
    if(newNode==NULL)
    {
        printf("Out of memory");
        exit(1);
    }
    newNode->Element=x;
    newNode->Next=NULL;
    
    return newNode;

}

List MakeEmpty(List L)//清空
{
    if(L != NULL)
        DeleteList(L);//非空则删除表
    L=(List)malloc(sizeof(Node));
    if(L==NULL)
    {
        printf("Out of memory");
        exit(1);
    }
    L->Next=NULL;
    return L;
}

int IsEmpty(List L) 
{
    return L->Next==NULL;
}

int IsLast(Position P,List L)
{
    return P->Next==NULL;
}

Position Find(ElementType x,List L)
{
    Position P;
    P=L->Next;
    while(P!=NULL&&P->Element!=x)
        P=P->Next;
    return P;  
}

void Delete(ElementType x,List L)//删除元素
{
    Position TmpCell;
    Position P;
    P=FindPrevious(x,L);
    if(!IsLast(P,L))
    {   TmpCell=P->Next;
        P->Next=TmpCell->Next;
        free(TmpCell);
    }
}
Position FindPrevious(ElementType x,List L)//找前驱
{
    Position P;
    P=L;
    while(P->Next!=NULL&&P->Next->Element!=x)
    {
        P=P->Next;
    }
    return P;
}
void Insert(ElementType x,List L,Position P)//插入
{
    Position TmpCell;
    TmpCell=NewNode(x);
    TmpCell->Next=P->Next;
    P->Next=TmpCell;
}
void DeleteList(List L)//删除表
{
    Position P,TmpCell;
    P=L->Next;
    L->Next=NULL;
    while(P!=NULL)
    {
        TmpCell=P->Next;
        free(P);
        P=TmpCell;
    }    
}
void PrintList(List L)
{
    Position Ptr;
    Ptr=L->Next;
    while(Ptr!=NULL)
    {
        printf("%5d",Ptr->Element);
        Ptr=Ptr->Next;
    }
    printf("\n");
}
