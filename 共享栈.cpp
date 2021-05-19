#include<stdio.h>
#include<stdlib.h>
#define  MAXSIZE 20 
typedef struct
{
	char S[MAXSIZE];
	int top1;
	int top2;
}Bistack;

void InitStack(Bistack*&h)//初始化共享栈 
{
	h=(Bistack*)malloc(sizeof(Bistack));
	h->top1=0;
	h->top2=MAXSIZE-1;
}

bool StackEmpty(Bistack*h,int i)//判断栈是否为空 
{
	switch(i)
	{
	case 0: 
    	if(h->top1==0)
    		return true;
    	else
    		return false;
    	break; 
	case 1:
    	if(h->top2==MAXSIZE-1)
    		return true; 
    	else
			return false;
    }
}

bool Push(Bistack*&h, int i,char x)//进栈操作 
{
	if(h->top1==h->top2)
		return false;
  
	switch(i)
	{
		case 0:
	 		h->S[h->top1]=x;
	  		h->top1++;
	 		break;
		case 1:
			h->S[h->top2]=x;
	 		h->top2--;
	 		break;
	}
	return true;  
}

bool Pop(Bistack*& h,int i,char &x)//出栈操作 
{
	switch(i)
	{
		case 0:
			if(h->top1==0)
				return false;
				h->top1--;
				x=h->S[h->top1];
			break;
		case 1:
		    if(h->top2==MAXSIZE-1)
		    return false;
		    h->top2++;
		    x=h->S[h->top2];
		    break;
			
	}
	return true;
}

void DestoryStack(Bistack*& h)
{
	free(h);
	h->top1=NULL;
	h->top2=NULL;
} 

int main()
{
	Bistack* h;
	int i; 
	char x='v', y,k;
	InitStack(h);
	Push(h,0,x);
	printf("进入0号栈的元素为%c\n",x);
	
	x = 'b';
    Push(h,1,x);
    printf("进入1号栈的元素为%c\n",x); 
    
    if (Pop(h,0,y)) 
    	printf("0号栈pop的元素为%c\n",y);
    if (StackEmpty(h,0))
    
    	printf("0号栈为空\n");
	else 
	    printf("0号栈不为空") ; 
	
    if (StackEmpty(h,1))
    
    	printf("1号栈为空");
	else
	    printf("1号栈不为空\n") ; 
	    DestoryStack(h);
}  






