#include <stdio.h>

int main()
{
    int i,j,k,m,n,a[10],b[10],c[20];

    printf("Enter the Size of First Array : ");
    scanf("%d",&n);
    printf("Enter the Size of Second Array : ");
    scanf("%d",&m);

    printf("Enter the Elements of First Array ... \n");
    for (int i = 0; i < n; i++)
    	scanf("%d",&a[i]);

    printf("Enter the Elements of Second Array ... \n");
    for (int i = 0; i < m; ++i)
    	scanf("%d",&b[i]);

    j=0;	k=0;

    for (int i = 0; i < (n+m); i++)
    {
    	if (j<n && k<m)
    	{
    		if(a[j]<b[k])
    			c[i]= a[j++];
    		else
    			c[i]= b[k++];
    	}
    	else if(j==n)
    		c[i]= b[k++];
    	else
    		c[i]= a[j++];
    }

    printf("\nSorted Array ... \n");

    for (int i = 0; i < (m+n); i++)
    {
    	printf(" %d ",c[i]);
    }

    printf("\n");
    return 0;
}