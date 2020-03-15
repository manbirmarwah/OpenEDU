/* Sum of series - Program to find sum of series 1 + 1/2! + 1/3! + ....... + 1/n! */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  n ;
  float  i , f=1 , s=0 ;
 
  clrscr() ;
 
  printf("Enter n: ") ;
  scanf("%d" , &n) ;
 
  for(i=1 ; i<=n ; i++)
  {
    f=f*i ;
    s=s+1/f ;
  }

  printf("Sum of the required series is %f" , s) ;

  getch() ;
}

/*
Output :

Enter n: 3
Sum of the required series is 1.666667
*/

