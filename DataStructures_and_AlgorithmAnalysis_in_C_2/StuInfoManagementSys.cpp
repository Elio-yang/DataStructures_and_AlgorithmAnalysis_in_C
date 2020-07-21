#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义一个学生信息的结构体
typedef struct
{
    char Name[10]; //姓名
    int Age;       //年龄
    int StuNum;    //学号
    int Score;     //总成绩
} Student;

//一个结点
typedef struct Node
{
    Student stu;        //学生信息（信息域）
    struct Node *pNext; //指向下一个结点的指针（指针域）
} Node;

Node *g_pHead = NULL; //定义头节点为空

//进行声明

//录入学生信息
void InputStudent();
//打印学生信息
void PrintStudent();
//保存学生信息
void SaveStudent();
//读取学员信息
void ReadStudent();
//统计所有学生人数
int CountStudent();
//查找学生信息
Node *FindStudent();
//修改某个学生的信息
void ModifyStudent();
//删除学生信息
void DeleteStudent();
//菜单
void Menu();
//交互
void KeyDown();
//一个子菜单
void ziMenu();
//主函数调用所有函数
int main()
{

    while (1)
    {
        Menu();
        KeyDown();
        //暂停
        system("pause");
        //清屏
        system("cls");
    }
    system("pause");
    return 0;
}
//菜单
void Menu()
{
    printf("********************************************************\n");
    printf("==============欢迎使用高校学生成绩管理系统==============\n");
    printf("\t=============请选择功能列表==============\n");
    printf("\t**************1.录入学生信息**************\n");
    printf("\t**************2.输出学生信息**************\n");
    printf("\t**************3.统计学生人数**************\n");
    printf("\t**************4.查找学生信息**************\n");
    printf("\t**************5.修改学生信息**************\n");
    printf("\t**************6.删除学生信息**************\n");
    printf("\t**************0.退 出 系  统**************\n");
    printf("********************************************************\n");
}
//交互 ：进行功能选择
void KeyDown()
{
    int k;
    printf("输入要选择的功能的序号(0~6)：\n");
    scanf("%d", &k);
    switch (k)
    {
    case 1: //录入学生信息
        InputStudent();
        SaveStudent();
        break;
    case 2: //打印学生信息
        PrintStudent();
        break;
    case 3: //统计所有学生人数
        printf("当前学生总人数为:%d\n", CountStudent());
        break;
    case 4: //查找学生信息
    {
        Node *pNode = FindStudent();
        if (pNode != NULL)
        {
            printf("学号:%d\t姓名:%s\t年龄:%d\t成绩:%d\n", pNode->stu.StuNum, pNode->stu.Name, pNode->stu.Age, pNode->stu.Score);
        }
        break;
    }
    case 5: //修改某个学生的信息
        ModifyStudent();
        SaveStudent();
        break;
    case 6: //删除学生信息
        DeleteStudent();
        SaveStudent();
        break;
    case 0:
        printf("欢迎再次使用！\n");
        break;
    default:
        printf("您的输入有误，请重新输入！\n");
        break;
    }
}

//录入学生信息
void InputStudent()
{
    //创建一个新结点
    Node *pNewNode = (Node *)malloc(sizeof(Node)); //malloc用于开辟动态内存 Node*是类型名 pNewNode是变量名
    pNewNode->pNext = NULL;                        //为了安全，一般都使下一个指针指向空
    //头插法
    if (g_pHead == NULL)
    {
        g_pHead = pNewNode; //头结点为空，就把新结点作为头节点
    }
    else
    {
        pNewNode->pNext = g_pHead; //头结点不空，把新结点放在头前
        g_pHead = pNewNode;        //新结点为头结点
    }
    printf("请输入学生姓名:\n");
    scanf("%s", pNewNode->stu.Name);
    printf("请输入学生学号:\n");
    scanf("%d", &pNewNode->stu.StuNum);
    printf("请输入学生年龄:\n");
    scanf("%d", &pNewNode->stu.Age);
    printf("请输入学生成绩:\n");
    scanf("%d", &pNewNode->stu.Score);
    printf("\n数据添加成功....\n");
}

//打印学生信息
void PrintStudent()
{
    system("cls");
    printf("********************************************************\n");
    printf("==============欢迎使用高校学生成绩管理系统==============\n");
    printf("********************************************************\n");
    //遍历链表
    Node *p;
    p = g_pHead;
    while (p != NULL) //	头指针不为空
    {
        printf("学号:%d\t 姓名:%s\t 年龄:%d\t 成绩:%d\n",
               p->stu.StuNum,
               p->stu.Name,
               p->stu.Age,
               p->stu.Score);

        p = p->pNext;
    }
}

//保存学生信息
void SaveStudent()
{

    //打开文件
    FILE *pFile = fopen("student.txt", "w");
    if (pFile == 0)
    {
        printf("打开文件失败\n");
        return;
    }
    //遍历链表
    Node *p; //定义一个指针
    p = g_pHead;
    while (p != NULL)
    {
        //给文件写入数据
        fwrite(&p->stu, 1, sizeof(Student), pFile); //一次写入一个结构体，大小为Student，保存在pFile中
        p = p->pNext;
    }
    //关闭文件
    fclose(pFile);
    printf("数据保存成功\n");
}

//读取学员信息
void ReadStudent()
{
    //打开文件
    FILE *pFile = fopen("student.txt", "r");
    if (pFile == 0)
    {
        printf("打开文件失败\n");
        return;
    }
    Student stu;
    //读取数据
    while (fread(&stu, 1, sizeof(Student), pFile)) //fread会返回读取的字节数
    {
        //创建一个新结点
        Node *pNewNode = (Node *)malloc(sizeof(Node)); //分配空间以存储数据
        //从文件中读取
        pNewNode->pNext = NULL;
        memcpy(pNewNode, &stu, sizeof(Student)); //把stu中的数据复制到 pNewNode中去 内存大小为student
        //头插法
        if (g_pHead == NULL)
        {
            g_pHead = pNewNode; //头为空，就把新结点作为头节点
        }
        else
        {
            pNewNode->pNext = g_pHead; //头不空，把新结点放在头前
            g_pHead = pNewNode;        //新结点为头结点
        }
    }
    //关闭文件
    fclose(pFile);
    printf("数据加载成功！");
}

//统计所有学生人数
int CountStudent()
{
    int Count = 0;
    //遍历链表
    Node *p; //定义一个指针
    p = g_pHead;
    while (p != NULL)
    {
        Count++;
        p = p->pNext;
    }
    return Count;
}

//查找学生信息
Node *FindStudent()
{
    int StuNum;
    printf("请输入要查找的学生的学号:\n");
    scanf("%d", &StuNum);
    //遍历链表
    Node *p;
    p = g_pHead;
    while (p != NULL)
    {
        if (p->stu.StuNum == StuNum)
        {
            return p;
        }
        p = p->pNext;
    }
    //遍历完链表也没有找到信息
    if (p == NULL)
    {
        printf("没有该学生的信息\n");
        return NULL;
    }
}

//修改某个学生的信息
void ModifyStudent()
{
    int xgStuNum;
    printf("请输入要修改学生信息的学号:\n");
    scanf("%d", &xgStuNum);

    //遍历链表
    Node *p;
    p = g_pHead;
    while (p != NULL)
    {
        if (p->stu.StuNum == xgStuNum)
        {
            int a;
            ziMenu();
            printf("输入要选择的功能：\n");
            scanf("%d", &a);

            switch (a)
            {
            case 1:
                printf("请输入要修改的姓名:\n");
                scanf("%s", p->stu.Name);
                break;
            case 2:
                printf("请输入要修改的年龄:\n");
                scanf("%d", &p->stu.Age);
                break;
            case 3:
                printf("请输入要修改的成绩:\n");
                scanf("%d", &p->stu.Score);
                break;
            default:
                printf("您的输入有误，请重新输入！\n");
                break;
            }
        }
        printf("修改成功！\n");
        p = p->pNext;

        return; //如果没有此语句，会接着进行if语句
    }
    if (p == NULL)
    {
        printf("没有该学生信息!\n");
        printf("无法进行修改！\n");
    }
}

//一个子菜单
void ziMenu()
{
    printf("************************\n");
    printf("1.输入要修改的姓名:\n");
    printf("2.输入要修改的成绩:\n");
    printf("3.输入要修改的成绩:\n");
    printf("************************\n");
}

//删除学生信息
void DeleteStudent()
{
    system("cls");
    int StuNum;
    printf("请输入要删除学生信息的学号:\n");
    scanf("%d", &StuNum);

    Node *p1;
    //判断是否是头结点
    //是头结点
    if (g_pHead->stu.StuNum == StuNum)
    {
        p1 = g_pHead;             //进行备份
        g_pHead = g_pHead->pNext; //头指针变为删除元素后的首指针
        free(p1);                 //释放节点
        return;
    }

    Node *p = g_pHead;
    Node *p2; //定义一个Node*类型的变量进行备份

    //不是头结点
    while (p->pNext != NULL)
    {
        if (p->pNext->stu.StuNum == StuNum)
        {
            p2 = p->pNext;              //把p->pNext中的数据备份到p2中去
            p->pNext = p->pNext->pNext; //删除该节点：指针跳过此节点			p2 p2->next p2next->next
            free(p2);                   //备份完成就释放
            return;
        }

        p = p->pNext; //指向下一个节点  接着循环
        if (p->pNext == NULL)
        {
            //判断是否到了链表的结尾
            break;
        }
    }
    //在while循环之前就为空，证明没有改学号
    if (p->pNext == NULL)
    {
        printf("没有该学生信息！\n");
    }
}
