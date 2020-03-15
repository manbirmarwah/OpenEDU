/* Sum of digits use recursive function to calculate sum of digits of an integer*/

#include  <stdio.h>
#include  <conio.h>

int  sum(int  n)
{
  if(n==0)
    return  0 ;
  else
    return( n%10 + sum(n/10) ) ;
}

void main()
{
  int  n ;

  clrscr() ;

  printf("Enter the number: ") ;
  scanf("%d" , &n) ;

  printf("Sum of digits of %d is %d" , n , sum(n) ) ;

  getch() ;
}

/*
Output:

Enter the number: 246
Sum of digits of 246 is 12
*/