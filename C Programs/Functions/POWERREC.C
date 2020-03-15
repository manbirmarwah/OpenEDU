/* 
Write a program using recursive function 'power' to compute x^n
power(x,n) = 1 , if n = 0
power(x,n) = x , if n = 1
power(x,n) = x * power(x,n-1) , otherwise 
*/

#include  <stdio.h>
#include  <conio.h>

float  power(float  x , int  n)
{
  if(n==0)
    return  1 ;
  else if(n==1)
    return  x ;
  else
    return  ( x * power(x , n-1) ) ;
}

void main()
{
  float  x ;
  int  n ;

  clrscr() ;

  printf("Enter x and n: ") ;
  scanf("%f %d" , &x , &n) ;

  printf("x raise to n = %f" , power(x,n) ) ;

  getch() ;
}

/*
Output:

Enter x and n: 2.5  3
x raise to n = 15.625000
*/
