#include<stdio.h>
#include<stdlib.h>
#define M 6
#define N 8 
#define MAXSIZE 48
int maze[M+2][N+2] = {
        { 1,1,1,1,1,1,1,1,1,1 },
        { 1,0,1,1,1,0,1,1,1,1 },
        { 1,0,0,1,0,0,1,1,1,1 },
        { 1,0,0,0,0,0,0,0,1,1 },
        { 1,0,1,1,1,0,1,1,1,1 },
        { 1,1,0,0,0,0,0,0,0,1 },
        { 1,0,1,1,0,0,1,1,0,1 },
        { 1,1,1,1,1,1,1,1,1,1 }
    };
typedef struct
{
	int i,j;
	int pre;
}ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int front,rear;
}SqQueue;

void print(SqQueue qu,int cur)
 {
 	int i=cur,ns=0;
 	ElemType *stack=(ElemType*)malloc(sizeof(ElemType)*cur);
	 int top=0;
	 do
	 {
	 	stack[top++]=qu.data[i];
	 	i=qu.data[i].pre;
	  } while(i!=-1);
	  printf("The maze pata:\n");
	  while(top!=0)
	  {
		ns++;
		top=top-1;
		printf("\t(%d,%d)",stack[top].i,stack[top].j);
		if((ns)%5==0)
			printf("\n");
	   } 
	   printf("\n");
	   free(stack);
 }


bool MazeShorttestPath(int xi,int yi,int xe,int ye)
{
	int i,j,di;
	ElemType e;
	SqQueue qu;
	qu.front=qu.rear=0;
	e.i=xi;e.j=yi;e.pre=-1;
	qu.data[qu.rear]=e;
	qu.rear++;
	maze[xi][yi]=-1;
	while(qu.front!=qu.rear)
	{
		e=qu.data[qu.front];
		qu.front++;
	    if(e.i==xe&&e.j==ye)
	    {
	    	print(qu,qu.front-1);
	    	return true;
		}
		for(di=0;di<4;di++)
		{
			switch(di)
			{
				case 0:i=e.i-1;j=e.j;break;
				case 1:i=e.i  ;j=e.j+1;break;
				case 2:i=e.i+1;j=e.j;break;
				case 3:i=e.i  ;j=e.j-1;break; 
			}
			if(maze[i][j]==0)
			{
				qu.data[qu.rear].i=i;qu.data[qu.rear].j=j;
				qu.data[qu.rear].pre=qu.front-1;
				qu.rear++;
				maze[i][j]=-1;
			}
		}
	}
	return false;
 } 
 
 int main()
 {
 	printf("µðÄãÂè") ; 
	MazeShorttestPath(1,1,6,8);
 	return 0;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
