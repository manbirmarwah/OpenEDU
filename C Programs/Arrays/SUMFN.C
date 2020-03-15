/* Sum of list  -  Program to calculate sum of list by passing an array to a function - May 2013 */

#include  <stdio.h>
#include  <conio.h>

int  findsum(int  x[ ] , int  n) ;

void main()
{
  int  i , n , x[50] ;

  clrscr() ;
  printf("Enter the number of elements: ") ;
  scanf("%d" , &n) ;
  printf("Enter the elements: \n") ;
  for(i=0 ; i<n ; i++)
    scanf("%d" , &x[i]) ;

  printf("Sum of elements in list is: %d \n" , findsum(x,n) ) ;

  getch();
}

int  findsum(int  x[ ] , int  n)
{
  int  i , sum=0;

  for(i=0 ; i<n ; i++)
        sum=sum+x[i] ;

  return  sum;
}
 


/*
Output:

Enter the number of elements: 4
Enter the elements: 
1 4 2 5
Sum of elements in list is: 12 
*/

