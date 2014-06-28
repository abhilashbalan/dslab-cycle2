//Expression tree
#include <stdio.h>
#include <stdlib.h>

struct node
{
	char data;
	float value;
	struct node *llink;
	struct node *rlink;
};
struct stack
{
	struct node *dataLink;
	struct stack *link;
};
struct node *makeNode(char data)
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->llink = NULL;
	newnode->rlink = NULL;
	return newnode;
}
void push(struct stack **top,struct node *exprnode)
{
	struct stack *newnode;
	newnode = (struct stack*)malloc(sizeof(struct node));
	newnode->dataLink = exprnode;
	newnode->link = NULL;
	if(*top == NULL)
		*top = newnode;
	else
	{
		newnode->link = *top;
		*top = newnode;
	}
}
struct node *pop(struct stack **top)
{
	if(*top == NULL)
	{
		printf("Stack underflow!");
		return NULL;
	}
	else
	{
		struct node *temp = (*top)->dataLink;
		(*top) = (*top)->link;
		return temp;
	}
}
void makeExpressionTree(struct node **root)
{
	int len,i;
	char expr[100];
	struct node *temp = NULL;
	struct stack *top = NULL;
	
	printf("Enter the expression:");
	scanf("%s",expr);
	for(len = 0;expr[len] != '\0';len++);
	
	for(i = 0;i < len;i++)
	{
		if(expr[i] >= 'a' && expr[i] <= 'z')
		{
			temp = makeNode(expr[i]);
			push(&top,temp);
		}
		else if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
		{
			temp = makeNode(expr[i]);
			temp->rlink = pop(&top);
			temp->llink = pop(&top);
			push(&top,temp);
		}
	}
	*root = pop(&top);
}
void getValues(struct node *root)
{
	if(root == NULL)
		return;
	else
	{
		
		getValues(root->llink);
		if(root->data >= 'a' && root->data <= 'z')
		{
			printf("Enter the value for %c:",root->data);
			scanf("%f",&root->value);
		}
		getValues(root->rlink);
	}
}

float evalTree(struct node *root)
{
	if(root->data >= 'a' && root->data <= 'z')
		return root->value;
	else
	{
		switch(root->data)
		{
			case '+':	return evalTree(root->llink) + evalTree(root->rlink);break;
			case '-':	return evalTree(root->llink) - evalTree(root->rlink);break;
			case '*':	return evalTree(root->llink) * evalTree(root->rlink);break;
			case '/':	return evalTree(root->llink) / evalTree(root->rlink);break;
		}
	}
	
}
int main()
{
	struct node *root;
	makeExpressionTree(&root);
	getValues(root);
	printf("%.2f\n",evalTree(root));
	return 0;
}

Output:
Enter the expression:ab*cd*+
Enter the value for a:1
Enter the value for b:2
Enter the value for c:3
Enter the value for d:4
14.00
s
