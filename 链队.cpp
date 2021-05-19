#include<stdio.h>
#include<stdlib.h>
#define ElemType int 
typedef struct QNode
{
	ElemType data;
	struct QNode*next;
}QNode,  *QueuePtr;
typedef struct
{
	QNode*front;
	QNode*rear;
}LinkQueue;

void InitQueue(LinkQueue*&Q)//初始化链队 
{
	Q=(LinkQueue*) malloc(sizeof(LinkQueue));
	Q->front=Q->rear=NULL;
}

void DestroyQueue(LinkQueue*&Q)//销毁队列 
{
	QNode*p=Q->front,*q;
	while(p!=NULL)
	{
		q=p->next;
		free(p);
		p=q;
	 } 
	 free(Q);
 } 
 
 bool QueueEmpty(LinkQueue*Q)//判断是否为空 
 {
 	if(Q->rear==NULL)
 	   return true;
 	else
 	   return false;
} 
  
 bool EnQueue(LinkQueue*&Q,ElemType&e)//入队 
 {
 	QNode*p;
 	p=(QNode*)malloc(sizeof(QNode));
 	p->data=e;
    p->next=NULL;
    if(Q->rear==NULL)
       Q->front=Q->rear=p;
    else
    {
    	Q->rear->next=p;
    	Q->rear=p;
	}
	return true;	
  } 
  
  bool DeQueue(LinkQueue *&Q,ElemType &e)//出队 
  {
  	QNode*p;
  	if(Q->rear==NULL)
  	     return false;
  	p=Q->front;
  	if(Q->front==Q->rear)
  	   Q->front=Q->rear=NULL;
  	else
  	   Q->front=p->next;
  	e=p->data;
  	free(p);
  	return true;
   } 

bool GetHead(LinkQueue *&Q,ElemType &e)//取队首元素 
{
	if(Q->rear==NULL)
	    return false;
	e=Q->front->data;
	    return true;	  	
 } 
  
int main()
{
	LinkQueue*Q;
	InitQueue(Q);
	int e;
	int arr[]={1,2,3,4};
	for(int i=0;i<4;i++)
	{
		if(EnQueue(Q,arr[i]))
		{
			printf("成功入队的元素为%d\n",arr[i]);
	    }
	}
    if(EnQueue(Q,e))
	    printf("该队为空\n");
	else
	    printf("该队不为空\n");
	if(DeQueue(Q,e))
	    printf("出队的值为%d\n",e);
	if(GetHead(Q,e))
	    printf("栈顶的元素为%d\n");
	DestroyQueue(Q); 
}
  
  
  

