//Dijkstra
#include <stdio.h>

void dijkstra(int dist[][1010],int d[],int nodes,int start)
{
	int i,j,selected[1010];
	for(i = 0;i <= nodes;i++)
	{
		d[i] = dist[start][i];
		selected[i] = 0;
	}
	selected[start] = 1;
	int small = start;
	
	for(i = 1;i <= nodes;i++)
	{
		for(j = 1;j <= nodes ;j++)
		{
			if(selected[j] != 1)
			{
				small = j;
				//break;
			}
		}
		
		
		for(j = 1;j <= nodes;j++)
		{
			if(selected[j] != 1 && (d[small] > d[j]))
			{
				small = j;
				
			}
		}
		selected[small] = 1;
		
		for(j = 1;j <= nodes;j++)
		{
			if(selected[j] != 1)
			{
				if(d[j] > (d[small] + dist[small][j]))
					d[j] = d[small]+dist[small][j];
			}
		}
	}
}

int main()
{
	int start,d[1010],mat[1010][1010],nodes,i = 0,j = 0,w = 0;
	
	for(i = 1;i < 1010;i++)
	{
		for(j = 1;j < 1010;j++)
		{
			if(i == j)
				mat[i][j] = 0;
			else
				mat[i][j] = 9999;
		}
	}
	scanf("%d",&nodes);
	scanf("%d%d%d",&i,&j,&w);
	while(i != -1 && j != -1 && w != -1)
	{
		mat[i][j] = w;
		//mat[j][i] = w;
		scanf("%d%d%d",&i,&j,&w);
	}
	scanf("%d",&start);
	dijkstra(mat,d,nodes,start);
	
	for(i = 1;i <= nodes;i++)
	{
		printf("%d\n",d[i]);
	}
	return 0;
	
}
Output:
6
0 1 10
0 5 100
1 2 1
2 5 80
2 3 20
3 4 50
2 4 1
2 5 80
4 5 30
0
0 10 11 31 12 42
