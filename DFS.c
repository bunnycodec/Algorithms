#include <stdio.h>

int source, G[20][20], visited[20], V,E;

void DFS(int i)
{
	int j;
	visited[i]=1;
	printf(" ---> %d",i);

	for(j=1; j<=V; j++)
		if(G[i][j]==1 && visited[j]==0)
			DFS(j);
}

void main()
{
	int i,j,v1,v2;

	printf("\t\t\tDepth First Search\n\n");
	printf("Enter the Number of Vertices : ");
	scanf("%d",&V);
	printf("Enter the Number of Edges : ");
	scanf("%d",&E);

	for (i = 1; i <= V; ++i)
	{
		for (j = 1; j <= V; ++j)
		{
			G[i][j]=0;
		}
	}

	for(i=1; i<=E; i++)
	{
		printf("Enter Edge No. %d (format V1 V2) : ",i);
		scanf("%d %d",&v1,&v2);
		G[v1][v2]=1;
	}

	printf("\nEnter the Source : ");
	scanf("%d",&source);
	DFS(source);
	printf("\n");
}