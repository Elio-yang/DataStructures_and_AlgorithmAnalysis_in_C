#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int element;
	struct Node* Next;
};

typedef struct Node* PtrToNode;
typedef PtrToNode Stack;
int  isEmpty(Stack S);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(int x, Stack S);
int  Top(Stack S);
void Pop(Stack S);
void FatalError(char*Statement);
void PrintStack(const Stack S);

int isEmpty(Stack S) {
	return S->Next == NULL;
}
char Error[3][100] = {
	"Must create a stack first",
	"Stack overflow!",
	"Empty Stack.",
};
void MakeEmpty(Stack S) {
	if (S == NULL) {
		FatalError(Error[1]);
	}
	else
	{
		while (!isEmpty(S))
		{
			Pop(S);
		}
	}
}
void Push(int x, Stack S) {
	PtrToNode Temp;
	Temp = (PtrToNode)malloc(sizeof(struct Node));
	if (Temp == NULL) {
		FatalError(Error[2]);
	}
	else
	{
		Temp->element = x;
		Temp->Next = S->Next;
		S->Next = Temp;
	}
}
int Top(Stack S) {
	if (!isEmpty(S)) {
		return S->Next->element;
	}
	FatalError(Error[3]);
	return 0;
}
void Pop(Stack S) {
	PtrToNode First;
	if (isEmpty(S)) {
		FatalError(Error[3]);
	}
	else
	{
		First = S->Next;
		S->Next = S->Next->Next;
		free(First);
	}
}
void DisposeStack(Stack S) {
	PtrToNode temp=(PtrToNode)malloc(sizeof(struct Node));
	PtrToNode temp2= (PtrToNode)malloc(sizeof(struct Node));
	temp = S->Next;
	if (isEmpty(S)) {
		FatalError(Error[3]);
	}
	while (temp->Next!=NULL) {
		temp2 = temp->Next;
		free(temp);
		temp=temp2;
	}
	free(S);
}
void FatalError(char*Statement) {
	printf("%s", Statement);
	exit(-1);
}
void PrintStack(const Stack S) {
	struct Node*pt = (struct Node*)malloc(sizeof(struct Node));
	pt = S;

	while (pt->Next!=NULL)
	{
		printf("%d\n", pt->element);
		pt = pt->Next;
	}
}

int main() {
	Stack S;
	S = (PtrToNode)malloc(sizeof(struct Node));
	if (S == NULL)
	{
		FatalError(Error[2]);
	}
	S->Next = NULL;
	MakeEmpty(S);
	Push(1, S);
	Push(2, S);
	Push(3, S);
//	PrintStack(S);
	int top1 = Top(S);
	printf("%d\n", top1);
	Pop(S);
	int top2 = Top(S);
	printf("%d\n", top2);
	Pop(S);
	int top3 = Top(S);
	printf("%d\n", top3);
	DisposeStack(S);

	system("pause");
	return 0;
}