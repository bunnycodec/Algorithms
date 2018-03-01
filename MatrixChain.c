#include<stdio.h>
#include<limits.h>

int s[20][20]={{0}};

void print_brackets(int i,int j)
{
	if(i==j)
		printf("A%d",i);
	else
	{
		printf("( ");
		print_brackets(i,s[i][j]);
		print_brackets(s[i][j]+1,j);
		printf(" )");
	}

}

int main()
{
	int n,i,counter,cost,k,j;
	
	printf("\nEnter Number of Matrices : ");
	scanf("%d",&n);
	
	int p[n+1],m[n+1][n+1];
	
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			m[i][j]=0;
	
		printf("Enter the Dimensions for Each Matrix ... \n\n");
	
		for(i=0;i<n;i++)
		{
			printf("A%d :",i+1);
			scanf("%d*%d",&p[i],&p[i+1]);
		}
	
		for(counter=2;counter<=n;counter++)
		{
			for(i=1,j=counter;i<=n-counter+1;i++,j++)
			{
				m[i][j]=INT_MAX;
				for(k=i;k<j;k++)
				{
					cost=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
	
					if(cost<m[i][j])
					{
						m[i][j]=cost;
						s[i][j]=k;
					}
				}
	
			}
		}
	
		printf("\nThe M Matrix is ... \n\n");
	
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				printf("%d\t",m[i][j]);
			printf("\n");
		}
	
		printf("\nThe S Matrix is ... \n\n");
	
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				printf("%d\t",s[i][j]);
			printf("\n");
		}
	
		printf("\nThe Resulting Sequence : ");
		print_brackets(1,n);
		printf("\n");
	}

