#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20
#define ElemType char 
typedef struct BTNode{
	ElemType data;
	struct BTNode*lchild;
	struct BTNode*rchild;
}BTNode;

void InitBiTree(BTNode *&T)//初始化二叉树 
{
	T = NULL;
}

void CreateBiTree(BTNode *&T, char *str)//创建二叉树 
{
	BTNode *St[MaxSize], *p = NULL;
	int top = -1, tag, j = 0;
	char ch;
	T = NULL;
	ch = str[j];
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; tag = 1; break;
		case ')':top--; break;
		case ',':tag = 2; break;
		default:p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (T == NULL)
				T = p;
			else
			{
				switch (tag)
				{
				case 1:St[top]->lchild = p;
					break;
				case 2:St[top]->rchild = p;
					break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}

void visite(BTNode *T)//访问二叉树 
{
	if (T == NULL)
		printf("The node does not exist");
	else
		printf("%c", T->data);
}


void PrintBiTree(BTNode *T, int level)//横向输出二叉树 
{
	if (T != NULL)
	{
		PrintBiTree(T->rchild, level + 1);
		if (level != 0)
		{
			for (int i = 0; i<4 * (level - 1); i++)
			{
				printf("%s", " ");
			}
			printf("%s", "---");
		}
		visite(T);
		printf("\n");
		PrintBiTree(T->lchild, level + 1);
	}
}

int BiTreeDepth(BTNode *T)//输出二叉树高度 
{
	int ldep = 0;
	int rdep = 0;
	if (T == NULL)
		return 0;
	else{
		ldep = BiTreeDepth(T->lchild);
		rdep = BiTreeDepth(T->rchild);
		return(ldep>rdep) ? (ldep + 1) : (rdep + 1);
	}
	
}

 BTNode*FindNode(BTNode*T, ElemType x)//查找结点 
{
	BTNode*p;
	if (T == NULL)
		return NULL;
	else if (T->data == x)
		return T;
	else
	{
		p = FindNode(T->rchild, x);
		if (p != NULL)
			return p;
		else
			return FindNode(T->rchild, x);
	}
}

void InOrderTraverse(BTNode *T)//中序遍历 
{
	if (T != NULL)
	{
		InOrderTraverse(T->lchild);
		visite(T);
		InOrderTraverse(T->rchild);
	}
}

void LevelTraverse(BTNode *T)//层次遍历 
{
	BTNode *p;
	BTNode *qu[MaxSize];
	int front, rear;
	front = rear = -1;
	rear++;
	qu[rear] = T;
	while (front != rear)
	{
		front = (front + 1) % MaxSize;
		p = qu[front];
		visite(p);
		if (p->lchild != NULL)
		{
			rear = (rear + 1) % MaxSize;
			qu[rear] = p->lchild;
		}
		if (p->rchild != NULL)
		{
			rear = (rear + 1) % MaxSize;
			qu[rear] = p->rchild;
		}
	}
}

int GetNodeNum(BTNode *T)//结点个数
{
	if (T == NULL)
		return 0;
	int lNum = GetNodeNum(T->lchild);
	int rNum = GetNodeNum(T->rchild);
	//printf("%d %d\n",lNum,rNum);
	return lNum + rNum + 1;
}


int main()
{
	BTNode *T;
	ElemType x;
	BTNode *p;
	int level = 0;
	char str[] = "(1(2,3(4(6),5)))";
	InitBiTree(T);
	CreateBiTree(T, str);
	puts("横向输出二叉树");
	//visite(T);
	PrintBiTree(T, level);
	puts("中序遍历");
	InOrderTraverse(T);
	puts(" ");
	puts("层次遍历");
	LevelTraverse(T);
	puts(" ");
	p=FindNode(T, '3');	
	if (p!=NULL&&p->rchild!=NULL)
	printf("3结点的左右孩子分别为：%c %c",p->lchild->data,p->rchild->data);
	puts(" ");
	puts("数的高度为");
	printf("%d", BiTreeDepth(T));
	puts(" ");
	printf("二插树结点个数为：%d\n", GetNodeNum(T));
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
