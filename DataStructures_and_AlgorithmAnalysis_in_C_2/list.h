#ifndef LIST_H_
#define LIST_H_
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

#define TSIZE 45
struct film
{
    char title[TSIZE];
    int rating;
};
typedef struct film Item;
typedef struct node
{
    Item item;
    struct node* next;
}Node;
typedef Node* List;
void CopyToNode(Item item,Node*pnode);
void InitiallizeList(List*plist);//plist pt linked_list(List_type==pt Node)
bool isEmpty(const List*plist);
bool isFull(const List*plist);
unsigned int ListItemCount(const List*plist);
bool addItem(Item item,List* plist);
void Traverse(const List*plist,void(*pfun)(Item item));
void makeEmpty(List*plist);
void InitiallizeList(List*plist){
    *plist=NULL;
}
bool isEmpty(const List*plist){
    return (*plist==NULL)?true:false;
}
bool isFull(const List*plist){
    Node*pt;
    bool isFull;
    pt=(Node*)malloc(sizeof(Node*));
    isFull=(pt==NULL)?true:false;
    free(pt);
    return isFull;
}
unsigned int ListItemCount(const List*plist){
    unsigned int count=0;
    Node*pstart=*plist;
    while(pstart!=NULL){
        ++count;
        pstart=pstart->next;
    }
    return count;
}
bool addItem(Item item,List* plist){
    Node* NewNode;
    Node*scan=*plist;
    NewNode=(Node*)malloc(sizeof(Node));
    if(NewNode==NULL){
        return false;
    }
    CopyToNode(item,NewNode);
    NewNode->next=NULL;
    if(scan==NULL){
        *plist=NewNode;
    }
    else{
        while(scan->next!=NULL){
            scan=scan->next;
        }
        scan->next=NewNode;
    }
    return true;
}
void Traverse(const List*plist,void(*pfun)(Item item)){
    Node*pstart=*plist;
    while(pstart!=NULL){
        (*pfun)(pstart->item);
        pstart=pstart->next;
    }
}
void makeEmpty(List*plist){
    Node*psave;
    while(*plist!=NULL){
        psave=(*plist)->next;
        free(*plist);
        *plist=psave;
    }
}
void CopyToNode(Item item,Node*pnode){
    pnode->item=item;
}
#endif