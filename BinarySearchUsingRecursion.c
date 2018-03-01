#include <stdio.h>

int Bsearch(int a[], int beg, int last, int search)
{
	int mid;
	if(beg==last)
	{
		if (a[beg]==search)
			return beg;
		else
			return (-1);
	}

	mid=(beg+last)/2;
	if(a[mid]==search)
		return mid;
	else if(a[mid]<search)
		return Bsearch(a,mid+1,last,search);
	else
		return Bsearch(a,beg,mid-1,search);
}

void main()
{
	int pos,i,n,a[10],search;

	printf("\nEnter the no. of Elements : ");
	scanf("%d",&n);
	printf("\nEnter the Array Elements ... \n");
	for (i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEnter the Number to be Searched : ");
	scanf("%d",&search);
	pos=Bsearch(a,0,n-1,search);
	if(pos!=-1)
		printf("\nThe Number is Found at Location : %d \n",(pos+1));
	else
		printf("\nNumber Not Found !!\n");
}