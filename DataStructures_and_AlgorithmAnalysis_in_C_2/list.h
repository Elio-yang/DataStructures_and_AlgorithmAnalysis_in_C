typedef int ElementType;

#ifndef _LIST_H

struct Node;
typedef struct Node*PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List CreatList();
List MakeEmpty(List L);
ElementType IsEmpty(List L);
ElementType IsLast(Position P, List L);
Position Find(ElementType x,List L);
void Delete(ElementType x,List L);
Position FindPrevious(ElementType x,List L);
void Insert(ElementType x,List L,Position P);
void DeleteList(List L);

Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
#endif



