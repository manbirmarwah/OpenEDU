/* power(m,n) - Use recursive function to find value of m^n where m is a real number and n is an integer greater than or equal to zero */ 

#include  <stdio.h>
#include  <conio.h>

float  power(float  m , int  n)
{
  if(n==0)
    return  1 ;
  else
    return  (m * power(m,n-1) ) ;
}

void main()
{
  float  m ;
  int  n ;

  clrscr() ;

  printf("Enter m and n: ") ;
  scanf("%f %d" , &m , &n) ;

  printf("m raise to n = %f" , power(m,n) ) ;

  getch() ;
}

/*
Output:

Enter m and n: 2.5   3
m raise to n = 15.625000
*/
