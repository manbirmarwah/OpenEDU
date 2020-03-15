/* Summation of n numbers using recursion  -  Program to calculate sum of list of numbers using recursion */

#include  <stdio.h>
#include  <conio.h>

int  findsum(int  x[ ] , int  n) ;

void  main()
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
  static  int  sum=0 ;

  if (n==0)
      return  sum ;
 
  sum=sum+x[n-1] ;
 
  return findsum(x,n-1) ;
}

 
/*
Output:

*/

