//Prims
#include <stdio.h>
#define GRAPH_SIZE 1001


void printmst(int graph[][GRAPH_SIZE],int tree[][GRAPH_SIZE],int n)
{
        int i,j;
        printf("\nThe edges to be included are:\n");
        for(i=1;i<=n;i++)
        {
                for(j=1;j<=n;j++)
                {
                        if(tree[i][j]==1)
                        {
                                printf("\n%d - %d  %d",i,j,graph[i][j]);
                         }
                 }
        }
        printf("\n");
}

void prims(int graph[][GRAPH_SIZE],int tree[][GRAPH_SIZE],int n)
{
        int selected[GRAPH_SIZE],i,min,j,ne,x,y;
        for(i=0;i<=n;i++)
        {
                selected[i]=0;
        }
        selected[1]=1;
        ne=1;
        while(ne<n)
        {
                min=9999;
                for(i=1;i<=n;i++)
                {
                        if(selected[i])
                        {
                                for(j=1;j<=n;j++)
                                {
                                        if(!selected[j] && min>graph[i][j])
                                        {
                                                min=graph[i][j];
                                                x=i;
                                                y=j;
                                        }
                                 }
                        }
                 }
                 tree[x][y]=1;
                 selected[y]=1;
                 ne++;
         }
         printmst(graph,tree,n);
}
    
                                
int main()
{
	int source,graph[GRAPH_SIZE][GRAPH_SIZE],tree[GRAPH_SIZE][GRAPH_SIZE],n,i=0,j=0,w=0;
	for(i = 1;i < GRAPH_SIZE;i++)
	{
		for(j = 1;j <GRAPH_SIZE;j++)
		{
			if(i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = 9999;
		        tree[i][j]=0;
		}
	}
	printf("\nEnter the no of vertices:");
	scanf("%d",&n);
	printf("\nEnter edge (-1 -1 to quit):");
	scanf("%d%d%d",&i,&j,&w);
	while(i!=-1 && j!=-1 && w!=-1)
        {
		graph[i][j] = w;
		graph[j][i]=w;
		printf("\nEnter edge (-1 -1 -1 to quit):");
		scanf("%d%d%d",&i,&j,&w);
	}
	prims(graph,tree,n);
	return 0;
}

Output:- 

Enter the no of vertices:3
Enter edge (-1 -1 -1 to quit):1 2 4
Enter edge (-1 -1 -1 to quit):1 3 5
Enter edge (-1 -1 -1 to quit):2 3 6
Enter edge (-1 -1 -1 to quit):-1 -1 -1
The edges to be included are:
1 - 2  4
1 - 3  5



