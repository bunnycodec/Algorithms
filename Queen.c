#include<stdio.h>
#include<math.h>
 
int board[20],k=1;
void queen(int,int);
 
int main()
{
 int n;
 
 printf("\n\t\t Queens Problem Using Backtracking \n");
 printf("Enter number of Queens:");
 scanf("%d",&n);

 queen(1,n);
 return 0;
}
 
void print(int n)
{
 int i,j;
 printf("\n\nSolution %d ... \n\n",k++);
 
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++) 
  {
   if(board[i]==j)
    printf("\tQ"); 
   else
    printf("\t-"); 
  }
  printf("\n");
 }
}
 
int place(int row,int column)
{
 int i;
 for(i=1;i<row;i++)
 {
  if(board[i]==column)
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))
    return 0;
 }
 
 return 1;
}
 
void queen(int row,int n)
{
 int column;
 for(column=1;column<=n;column++)
 {
  if(place(row,column))
  {
   board[row]=column; //no conflicts so place queen
   if(row==n) //dead end
    print(n); //printing the board configuration
   else //try queen with next position
    queen(row+1,n);
  }
 }
}