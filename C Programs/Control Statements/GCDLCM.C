/* GCD-LCD - Program to find GCD of two numbers using Euclid's algorithm and then find LCM  */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  m , n , r , a , b ;

  clrscr() ;

  printf("Enter 2 numbers: ") ;
  scanf("%d %d", &m , &n) ;

  a=m ;
  b=n ;
  while(n>0)
  {
    r=m%n ;
    m=n ;
    n=r ;
  }

  printf("GCD is: %d \n" , m) ;

  printf("LCM is: %d" , a*b/m) ;
 
  getch() ;
}

/*
Output 1:

Enter 2 numbers: 24  18
GCD is: 6 
LCM is: 72

Output 2:

Enter 2 numbers: 18  24
GCD is: 6 
LCM is: 72

Output 3:

Enter 2 numbers: 9  7
GCD is: 1 
LCM is: 63
*/


