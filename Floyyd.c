#include <stdio.h>
#include <stdlib.h>

void print_path(int **b, int i, int j)
{
	if(b[i][j]==-1)
		printf("%d", i);
	else
	{
		print_path(b,i,b[i][j]);
		printf("--->%d\n", j);
	}
}

int main()
{
	int i,j,k,n,**a,**b;

	printf("Enter the Vertices : ");
	scanf("%d",&n);

	a=malloc(sizeof(int *)*n);
	b=malloc(sizeof(int *)*n);

	for(i=0; i<n; i++)
	{
		a[i]=malloc(sizeof(int *)*n);
		b[i]=malloc(sizeof(int *)*n);
	}

	for(i=0; i<n; i++)
		b[i][i]=-1;

	printf("Enter the Matrix Elements \n");
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]!=999 && b[i][j]!=-1)
				b[i][j]=i;
		}

		for(k=0; k<n; k++)
			for(i=0; i<n; i++)
				for(j=0; j<n; j++)
					if(a[i][k]+a[k][j]<a[i][j])
					{
						a[i][j]= a[i][k]+a[k][j];
						b[i][j]=k;
					}

		printf("\nPredecessor Matrix ... \n\n");
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
				printf("%d\t",b[i][j]);
			printf("\n");
		}

		printf("\nDistance Matrix ... \n\n");
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(a[i][j]==999)
					printf("#\t");
				else
					printf("%d\t",a[i][j]);
			}
		
			printf("\n");
		}

		printf("Enter the Source and Destination : ");
		scanf("%d%d",&i,&j);
		print_path(b,i,j);
		return 0;
}