/* Sum of natural numbers - Write a recursive function to calculate 1+2+3+...+n */

#include  <stdio.h>
#include  <conio.h>

long  sum(int  n)
{
  if(n==1)
    return  1 ;
  else
    return ( n + sum(n-1) ) ;
}

void main()
{
   int  n ;

   clrscr() ;

   printf("Enter n: ") ;
   scanf("%d" , &n) ;

   printf("Sum of first %d natural numbers is %ld" , n , sum(n) ) ;

   getch() ;
}

/*
Output:

Enter n: 3
Sum of first 3 natural numbers is 6
*/
