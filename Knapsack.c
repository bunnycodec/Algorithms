#include<stdio.h>
 
void knapsack(int n, float weight[], float profit[], float capacity, int object[])
{
   float x[20], tp = 0, u;
   int i;
   u = capacity;
 
   for (i = 0; i < n; i++)
      x[i] = 0.0;
 
   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      else {
         x[i] = 1.0;
         tp += profit[i];
         u -= weight[i];
      }
   }
 
   if (i < n)
      x[i] = u / weight[i];
 
   tp = tp + (x[i] * profit[i]);
 
   printf("\nThe Result Vector is... \n");
   for (i = 0; i < n; i++)
      printf("Object( %d ) ---> %f\n",object[i],x[i]);
 
   printf("\nMaximum Profit is : %f\n", tp);
 
}
 
int main() 
{
   float weight[20], profit[20], capacity, ratio[20], temp;
   int num, i, j, object[20];
   
 
   printf("\nEnter the No. of Objects : ");
   scanf("%d", &num);
 
   printf("\nEnter the weights and Profits of Each Object ...\n");
   for (i = 0; i < num; i++) 
   {
      scanf("%f %f", &weight[i], &profit[i]);
      object[i]=i+1;
      ratio[i]= profit[i]/weight[i];
   }
 
   printf("\nEnter the Capacity : ");
   scanf("%f", &capacity);
 
   for (i = 0; i < num; i++) 
   {
      for (j = i + 1; j < num; j++) 
      {
         if (ratio[i] < ratio[j]) 
         {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;
 
            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;
 
            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;

            temp = object[j];
            object[j] = object[i];
            object[i] = temp;
         }
      }
   }
 
   knapsack(num, weight, profit, capacity, object);
   return 0;
}