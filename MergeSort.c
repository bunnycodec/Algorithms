#include <stdio.h>

void merge(int, int, int);
int a[10]; int b[20];

void mergesort(int low, int high)
{
	if(low<high)
	{
		int mid;
		mid=(low+high)/2;
		mergesort(low,mid);
		mergesort(mid+1,high);
		merge(low,mid,high);
	}
}

void merge(int low, int mid, int high)
{
	int l, m, i;

   for(l = low, m = mid + 1, i = low; l <= mid && m <= high; i++) {
      if(a[l] <= a[m])
         b[i] = a[l++];
      else
         b[i] = a[m++];
   }
   
   while(l <= mid)    
      b[i++] = a[l++];

   while(m <= high)   
      b[i++] = a[m++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void main()
{
	int i,n;

	printf("\nEnter the Array Size : ");
	scanf("%d",&n);
	printf("\nEnter the Array Elements ... \n");
	for (i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	
	mergesort(0,n-1);
	printf("\nThe Sorted Array ...\n");

	for (i = 0; i < n; ++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}