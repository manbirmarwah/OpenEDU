/* Sum of series - Program to find sum of series 1 + 1/2 + 1/3 + ....... + 1/n */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  n ;
  float  i , s=0 ;
 
  clrscr() ;
 
  printf("Enter n: ") ;
  scanf("%d" , &n) ;
 
  for(i=1 ; i<=n ; i++)
    s=s+1/i ;  

  /* i has to be float in the above expression. If i is int then s is always 1.000000 since 1/i will be 0 for all i>1  */

  printf("Sum of the required series is %f" , s) ;

  getch() ;
}

/*
Output :

Enter n: 3
Sum of the required series is 1.833333
*/

