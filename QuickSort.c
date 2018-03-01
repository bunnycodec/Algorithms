#include<stdio.h>

void quicksort(int [10],int,int);

int part(int a[],int beg,int last)
{
  int index=beg,temp,i;

  for (i = beg; i < last; ++i)
  {
    if(a[i]<=a[last])
    {
      temp=a[i];
      a[i]=a[index];
      a[index]=temp;
      index+=1;
    }
  }

  temp=a[index];
  a[index]=a[last];
  a[last]=temp;
  return index;

}


void quicksort(int a[], int beg, int last)
{
  int index;

  if(beg<last)
  {
    index=part(a,beg,last);
    quicksort(a,beg,index-1);
    quicksort(a,index+1,last);
  }
}


void main()
{
  int x[20],size,i;

  printf("Enter Size of the Array: ");
  scanf("%d",&size);

  printf("Enter %d Elements ...\n",size);
  for(i=0;i<size;i++)
    scanf("%d",&x[i]);

  quicksort(x,0,size-1);

  printf("\nSorted Elements ...\n");
  for(i=0;i<size;i++)
    printf("%d ",x[i]);
  printf("\n");

}