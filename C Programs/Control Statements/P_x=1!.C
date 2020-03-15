/* Pattern problem
x=1!+3!+5!+7!+9!+...
*/

#include <stdio.h>
#include <conio.h>

void main()
{
  int  i , n ;

  clrscr() ;

  printf("Enter n:") ;
  scanf("%d" , &n) ;
  printf("Required Pattern is as shown:\n") ;
  printf("x=1!") ;
  for(i=3 ; i<=2*n-1 ; i=i+2)
    printf("+%d!" , i) ;

  getch() ;
}

/*
Output:

Enter n:3
Required Pattern is as shown:
x=1!+3!+5!
*/
