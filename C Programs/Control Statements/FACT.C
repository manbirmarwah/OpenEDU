/* Factorial - Program to find factorial of a given number (using for loop) */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  i , n ;
  long  f=1 ;  /* Factorials are long numbers */

  clrscr() ;

  printf("Enter an integer greater than or equal to zero: ") ;
  scanf("%d" , &n) ;

  for(i=1 ; i<=n ; i++)
    f=f*i ;

  printf("Factorial of %d is %ld" , n , f) ;

  getch() ;
}
/*
Output 1:

Enter an integer greater than or equal to zero: 0
Factorial of 0 is 1

Output 2:

Enter an integer greater than or equal to zero: 3
Factorial of 3 is 6
*/



