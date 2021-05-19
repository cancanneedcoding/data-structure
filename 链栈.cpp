#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#define ElemType int
typedef struct LinkNode
{
	ElemType data;
	struct LinkNode *next;
 } LinkStack;
 
 
 void InitStack(LinkStack *&S)//初始化栈 
 {
 	S=(LinkStack*)malloc(sizeof(LinkStack));
 	S->next=NULL;
 }
 
 bool StackEmpty(LinkStack*S)//判断栈是否为空 
 {
 	if(S->next==NULL)
 	return true;
 	else
 	return false; 
  } 
  
  bool Push(LinkStack*&S,char e)//进栈 
  {
  	LinkStack *p;
  	p=(LinkStack *)malloc(sizeof(LinkStack));
  	p->data=e;
  	p->next=S->next;
  	S->next=p;
  	return true;
   } 
   
   
   bool Pop(LinkStack *&S,ElemType &e)//出栈 
   {
   	LinkStack *p;
   	if(S->next==NULL)
   	return false;
   	p=S->next;
   	S->next=p->next;
   	e=p->data;
   	free(p);
   	return true;
   }
   
   
   bool GetTop(LinkStack*&S,ElemType &e)//取栈顶元素 
   {
   	if(S->next==NULL)
   	return false;
   	e=S->next->data;
   	return false;
   }
   
   void DestroyStack(LinkStack*&S)//销毁栈 
   {
   	LinkStack *q,*p=S;
   	while(p!=NULL)
   	{
   		q=p;
   		p=p->next;
   		free(q);
	   }
	} 
   
   int main()
  {
   	LinkStack *S,*q;
	   int e;
	   char arr[]={'H','e','l','l','o'};
	   InitStack(S);
	   StackEmpty(S);
	    for(int i=0;i<5;i++)
	    {
	    	Push(S,arr[i]);
	    	printf("进栈成功，进栈元素为%c\n",arr[i]) ;
		}	
		GetTop(S,e);
		Pop(S,e);
		GetTop(S,e);
  } 
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
