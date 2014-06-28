//Priority queues
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	int prio;
	struct node *link;
};

void enqueue(struct node **front,struct node **rear,int data,int prio)
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->prio = prio;
	newnode->link = NULL;
	if(*front == NULL)
		*front = *rear = newnode;
	else
	{
		(*rear)->link = newnode;
		*rear = newnode;
	}
}

struct node *dequeue(struct node **front)
{
	if(*front == NULL)
	{
		printf("Queue is empty!");
		return NULL;
	}
	else
	{
		struct node *hiprio;
		struct node *trav = hiprio = *front,*hipar;
		while(trav->link != NULL)
		{
			if(trav->link->prio > hiprio->prio)
			{
				hiprio = trav->link;
				hipar = trav;
			}
			trav = trav->link;
		}
		
		if(hiprio == *front)
			*front = (*front)->link;
		else
		{
			hipar->link = hiprio->link;
		}
		return hiprio;
	}
}

int main()
{
	struct node *front = NULL,*rear = NULL,*temp;
	int data,prio,done = 1,choice;
	//1.Push 2.Pop
	while(done == 1)
	{
		printf("\n:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	scanf("%d%d",&data,&prio);enqueue(&front,&rear,data,prio);break;
			case 2:	temp = dequeue(&front);
					if(temp != NULL)
						printf("%d %d",temp->data,temp->prio);
					break;
			default:done = 0;break;
			
		}
	}
	return 0;
}
Output:
:1
10 15

:1
11 20

:1
12 100

:1
13 50

:2
12 100
:2
13 50
:2
11 20
:2
10 15
:2
Queue is empty!
:

