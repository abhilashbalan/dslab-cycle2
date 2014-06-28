//BST
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
};

void insert(struct node **root,int data)
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->llink = NULL;
	newnode->rlink = NULL;
	if(*root == NULL)
	{
		*root = newnode;
	}
	else
	{
		struct node *trav = *root,*prev;
		while(trav != NULL)
		{
			prev = trav;
			if(data > trav->data)
			{
				trav=trav->rlink;
			}
			else if(data < trav->data)
			{
				trav=trav->llink;
			}
			else
			{
			 	printf("Duplicate\n");
			 	return;
			} 
		}
		if(prev->data>data)
		{
			prev->llink=newnode;
		}
		else
			prev->rlink=newnode;	
	}
}

void search(struct node *root,int data)
{
	if(root != NULL)
		printf("%d\n",root->data);
	if(root == NULL)
	{
		printf("Absent\n");//printf("Element not found!");
		return;
	}
	else if(root->data == data)
	{
		
		return;
	//	return root;
	}
	else if(data > root->data)
	{
		search(root->rlink,data);
	}
	else if(data < root->data)
	{
		search(root->llink,data);
	}
}

void preorder(struct node *root)
{
	if(root != NULL)
	{
		printf("%d\n",root->data);
		preorder(root->llink);
		preorder(root->rlink);
	}
} 
void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->llink);
		printf("%d\n",root->data);
		inorder(root->rlink);
	}
} 

void postorder(struct node *root)
{
	if(root != NULL)
	{
		postorder(root->llink);
		postorder(root->rlink);
		printf("%d\n",root->data);
	}
}
struct node * inorder_successor(struct node *ptr)
{
        struct node *p=ptr->rlink;
        while(p->llink!=NULL)
        {
                p=p->llink;
        }
        return p;
}
struct node * inorder_predecessor(struct node *ptr)
{
        struct node *p=ptr->llink;
        while(p->rlink!=NULL)
        {
                p=p->rlink;
        }
        return p;
}
struct node * delete(struct node *ptr,int val)
{
	struct node *temp;
	if(ptr == NULL)
	{
	        return ptr;
	}
	else if(val<(ptr)->data)
	{
	        ptr->llink=delete(ptr->llink,val);
	}
	else if(val>ptr->data)
	{
	        ptr->rlink=delete(ptr->rlink,val);
	}
	else
	{
		if(ptr->rlink != NULL)
		{
				temp=inorder_successor(ptr);
		        ptr->data=temp->data;
		        ptr->rlink=delete(ptr->rlink,temp->data);
               
		}
		else if(ptr->llink != NULL)
		{
				temp=inorder_predecessor(ptr);
		        ptr->data=temp->data;
		        ptr->llink=delete(ptr->llink,temp->data);
               
		}
		else
		{
			return NULL;
		}
               
	}
	return ptr;
}		


int main()
{
	struct node *root = NULL;
	int data,choice,done = 0;
	
	while(done == 0)
	{
		
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
				scanf("%d",&data);
				insert(&root,data);
				break;
			case 2:	
				scanf("%d",&data);
				root = delete(root,data);
				break;
			
			case 3:	//printf("pre");
				preorder(root);break;
			case 4:	//printf("in");
				inorder(root);break;
			case 5:	//printf("post");
				postorder(root);break;
			case 6: 
				scanf("%d",&data);
				search(root,data);
				break;
			case 7: done = 1;break;
			default:done = 1;break;
		}
	}
	return 0;
}
Output 
1 10 1 20 1 5 1 6 1 15 3 
10
5
6
20
15


	
