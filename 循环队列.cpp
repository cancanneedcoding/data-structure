#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 48
#define ElemType int
typedef struct
{
	int data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue*&Q)//初始化队列
{
	Q = (SqQueue*)malloc(sizeof(SqQueue));
	Q->front = Q->rear = 0;
}

void DestroyQueue(SqQueue*&Q)//销毁队列
{
	free(Q);
}

bool QueueEmpty(SqQueue*Q)//判断队列是否为空
{
	if (Q->front == Q->rear)
		return true;
	else
		return false;
}

bool QueueFull(SqQueue*Q)//判断队列是否满
{
	if (Q->front == (Q->rear + 1) % MAXSIZE)
		return true;
	else
		return false;
}

bool EnQueue(SqQueue*&Q, ElemType &e)//入队
{
	if (Q->front == (Q->rear + 1) % MAXSIZE)
		return false;
	Q->data[Q->rear] = e;
		Q->rear = (Q->rear + 1) % MAXSIZE;
		return true;
}

	bool DeQueue(SqQueue*&Q,ElemType &e)//出队
    {
		if (Q->front == Q->rear)
			return false;
		e = Q->data[Q->front];
		Q->front = (Q->front + 1) % MAXSIZE;
		return true;
	}

	bool GetHead(SqQueue*Q, ElemType&e)//取队首元素
	{
		if(Q->front == Q->rear)
			return false;
		e = Q->data[Q->front];
		return true;
	}

	int main()
	{
		SqQueue*Q;
		int arr[]={0,1,2,3,4};
		int e,a;  
		InitQueue(Q);
		if(QueueEmpty(Q))
		  printf("该队为空\n");
		  else
		  printf("该队不为空\n");
		for(int j=0;j<5;j++){		
		    EnQueue(Q,arr[j]);
			printf("入队的元素为%d\n",arr[j]); 
	       }
	    if(QueueFull(Q))		
	    	printf("该队已满\n");		
			else 
			printf("该队未满\n"); 
		DeQueue(Q,a);
		    printf("出队的元素为%d\n",a) ; 
		if(GetHead(Q,e))
		{
			printf("队首元素为%d",e);
		}
		DestroyQueue(Q); 
     }
