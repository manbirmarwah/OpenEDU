/* Divisible - Program to check whether a given number is divisible by both 5 and 2 */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  n ;

  clrscr() ;

  printf("Enter any integer: ") ;
  scanf("%d" , &n) ;

  if( (n%5 == 0) && (n%2 == 0) )
    printf("%d is divisible by both 5 and 2" , n) ;
  else
    printf("%d is either not divisible by both 5 and 2 or one of them" , n) ;

  getch() ;
}

/*
Output1:

Enter any integer: 20
20 is divisible by both 5 and 2

Output2:

Enter any integer: 7
7 is either not divisible by both 5 and 2 or one of them
*/
