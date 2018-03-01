#include <stdio.h>
#include <math.h>
 
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

int main()
{
    int i,arr[1000],n;
    
    printf("\nEnter number of Elements  :  ");
      scanf("%d", &n);
 
    printf("Enter %d Integers ...\n", n);
 
    for (i=0; i<n; i++) 
    {
      scanf("%d", &arr[i]);
    }
 
    insertionSort(arr, n);
    
    printf("Sorted list in Ascending Order  :  ");
    for (i=0; i<n; i++)
       printf("%d ", arr[i]);
    printf("\n\n");
 
    return 0;
}