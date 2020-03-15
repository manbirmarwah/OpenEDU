/* power(m,n) - Write a non-recursive function to find m^n where m is a real number and n is an integer */

#include  <stdio.h>
#include  <conio.h>
#include  <stdlib.h>

float  power(float  m , int  n)
{
  int  i ;
  float  result=1 ;

  for(i=1 ; i<=abs(n) ; i++)
     result=result*m;

  if(n<0) 
    return  (1/result) ;
  else
    return  result;
}

void main()
{
  int  n ;
  float  m ;

  clrscr() ;
  printf("Enter m and n: ");
  scanf("%f  %d" , &m , &n);
  printf("m raise to n is %f" , power(m,n) );

  getch();
}

/*
Output1:

Enter m and n: 2.5  3
m raise to n is 15.625000

Output2:

Enter m and n: 2  -3
m raise to n is 0.125000
*/
