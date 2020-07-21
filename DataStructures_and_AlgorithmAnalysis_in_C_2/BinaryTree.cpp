#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

typedef struct tree
{
    Node *root;
} Tree;

void treeInsert(Tree *tree, int value);
void midTraverse(Node *node);
void treeDestory(Node *node);

int main()
{
    int i = 0;
    Tree *tree =(Tree*)malloc(sizeof(Node));
	tree->root = NULL;
    int n;
    printf("Total Input N:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        treeInsert(tree, temp);
    }
    midTraverse(tree->root);
    treeDestory(tree->root);
    system("pause");
    return 0;
}

void treeInsert(Tree *tree, int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    if (tree->root == NULL)
    {
        tree->root = node;
    }
    else
    {
        Node *temp = tree->root;
        while (temp != NULL)
        {
            if (value < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = node;
                    return;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = node;
                    return;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}
void midTraverse(Node *node)
{
    if (node != NULL)
    {
        midTraverse(node->left);
        printf("%d\n", node->data);
        midTraverse(node->right);
    }
}
void treeDestory(Node *node)
{
    if (node != NULL)
    {
        treeDestory(node->left);
        treeDestory(node->right);
        printf("Free node:%d \n", node->data);
        free(node);
        node = NULL;
    }
}
