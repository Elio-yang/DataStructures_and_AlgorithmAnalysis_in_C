#include<stdio.h>
struct Node
{
	int data;
	struct Node*next;
};
struct Node*creatList()
{
	struct Node*headNode = (struct Node*)malloc(sizeof(struct Node));
	//headNode ��Ϊ�˽ṹ�����
	//����ʹ��ǰ����ʼ��
	headNode->data = 1;
	headNode->next = NULL;
	return headNode;
}
struct Node*creatNode(int data)
{
	//�����ڵ�
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
	Node2.next = &Node3;//�ṹ�����ͨ���ṹ��ָ������
	system("pause");//��̬������
	*/
	/*
	1.��������
	2.�����ڵ�
	3.����ڵ�
	4.ɾ���ڵ�
	5.��ӡ����
	*/
	
	struct Node*list = creatList();
	insertNodeByHead(list, 1);
	insertNodeByHead(list, 2);
	insertNodeByHead(list, 3);

	printList(list);

	return 0;
}