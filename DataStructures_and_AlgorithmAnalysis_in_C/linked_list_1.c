#include<stdio.h>
struct Node
{
	int data;
	struct Node*next;
};
struct Node*creatList()
{
	struct Node*headNode = (struct Node*)malloc(sizeof(struct Node));
	//headNode 成为了结构体变量
	//变量使用前被初始化
	headNode->data = 1;
	headNode->next = NULL;
	return headNode;
}
struct Node*creatNode(int data)
{
	//创建节点
	struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void printList(struct Node*headNode)
{
	struct Node*pMove = headNode->data;
	while (pMove)
	{
		printf("%d", pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}
void insertNodeByHead(struct Node*headNode, int data)
{
	struct Node*newNode = creatNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}


int main()
{
	/*struct Node Node1 = { 1,NULL };
	struct Node Node2 = { 2,NULL };
	struct Node Node3 = { 3,NULL };

	Node1.next = &Node2;
	Node2.next = &Node3;//结构体变量通过结构体指针连接
	system("pause");//静态的链表
	*/
	/*
	1.创建链表
	2.创建节点
	3.插入节点
	4.删除节点
	5.打印链表
	*/
	
	struct Node*list = creatList();
	insertNodeByHead(list, 1);
	insertNodeByHead(list, 2);
	insertNodeByHead(list, 3);

	printList(list);

	return 0;
}