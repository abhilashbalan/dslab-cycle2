//Depth first search
#include <stdio.h>

void push(int array[],int size,int *top,int element)
{
	if(*top == size)
		printf("Stack Overflow!");
	else
	{
		array[*top] = element;
		*top = *top + 1;
	}
}
int pop(int array[],int *top)
{
	if(*top == 0)
	{
		printf("Stack Underflow!");
		return -1;
	}
	else
	{
		*top = *top - 1;
		return array[*top];
	}
}

void dfs(int mat[][1010],int size,int start)
{
	int temp,selected[1010],i,stack[1010],top = 0;
	for(i = 0;i <= size;i++)
		selected[i] = 0;
	push(stack,1010,&top,start);
	selected[start] = 1;
	while(top > 0)
	{
		temp = pop(stack,&top);
		printf("%d",temp);
		
		for(i = 1;i <= size;i++)
		{
			if(selected[i] != 1 && mat[temp][i] == 1)
			{
				push(stack,1010,&top,i);
				selected[i] = 1;
			}
		}
		if(top > 0)
			printf(" ");
	}	
	
}

int main()
{
	int i = 0,j = 0,size,mat[1010][1010],start;
	scanf("%d",&size);
	
	scanf("%d%d",&i,&j);
	while(i != -1 && j != -1)
	{
		mat[i][j] = 1;
		scanf("%d%d",&i,&j);
	}
	scanf("%d",&start);
	dfs(mat,size,start);
	return 0;
	
}
Output
5
1 2
1 5
1 4
4 3
-1 -1
1
1 5 4 3 2
