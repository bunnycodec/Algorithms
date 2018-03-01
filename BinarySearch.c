#include <stdio.h>

int main()
{
	int a[20], i, n, beg, x, end, mid;
		
	printf("Enter the Number of Elements : ");
	scanf("%d",&n);
	printf("Enter the Elements \n");
	for(i=0; i<n; i++)
	scanf("%d", &a[i]);

	printf("Enter the Search Element : ");
	scanf("%d", &x);
	
	beg = 0;
	end = n-1;
	
	while(beg <= end)
	{
		mid = (beg + end) / 2;
		if(x == a[mid])
		{
			printf("\n%d is Present at %d Position\n",x,mid+1);	
			break;
		}
		else if(a[mid]>x)
			end= mid-1;
		else
			beg= mid+1;;
	}

	if(beg>end)
		printf("No Such Element Exist");
		
	return 0;
}
