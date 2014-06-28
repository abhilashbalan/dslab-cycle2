//Breadth first search

#include <stdio.h>

void enqueue(int array[],int *rear,int size,int element)
{
	if(*rear==size)
	{
		printf("Queue is full\n");
	}
	else
	{
		array[*rear]=element;
		*rear=*rear+1;
	}
}
int dequeue(int array[],int *front,int *rear)
{
	if(*front==*rear)
	{
		printf("Queue is empty\n");
	}
	else
	{
	 int temp;
	 temp=array[*front];
	 *front=*front+1;
	 return temp;
	 }
}
void bfs(int mat[][1010],int size,int start)
{
	int temp,selected[1010],i,queue[1010],front = 0,rear = 0;
	for(i = 0;i <= size;i++)
		selected[i] = 0;
	enqueue(queue,&rear,1010,start);
	selected[start] = 1;
	while(front != rear)
	{
		temp = dequeue(queue,&front,&rear);
		printf("%d",temp);
		for(i = 1;i <= size;i++)
		{
			if(selected[i] != 1 && mat[temp][i] == 1)
			{
				enqueue(queue,&rear,1010,i);
				selected[i] = 1;
			}
		}
		if(front != rear)
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
	bfs(mat,size,start);
	return 0;
	
}
Output
5   
1 2
1 5
1 3 
2 3
3 4
4 5
-1 -1
1
1 2 3 5 4
