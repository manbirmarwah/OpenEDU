/* Quadratic Equation - Program to find roots of a quadartic equation */

#include  <stdio.h>
#include  <conio.h>
#include  <math.h>    /* for sqrt() */
#include  <stdlib.h>   /* for abs() */

void main()
{
  float  a , b , c , d , r , r1 , r2 , real , imag ;

  clrscr() ;

  printf("Enter three co-efficients: ") ;
  scanf("%f %f %f", &a , &b , &c) ;

  d=b*b-4*a*c ;

  if(d==0)
  {
    printf("Root is real \n") ;
    printf("Root is %f \n" , -b/(2*a) ) ;
  }
  else if(d>0)
  {
    printf("Roots are real \n") ;
    r=sqrt(d) ;
    r1=(-b+r)/(2*a) ;
    r2=(-b-r)/(2*a) ;
    printf("Roots are %f and %f \n" , r1 , r2) ;
  }
  else
  {
    printf("Roots are imaginary \n") ;
    r=sqrt(-d);
    real=-b/(2*a) ;
    imag=r/(2*a) ;
    printf("Root1= %f + %f i \n" , real , imag) ;
    printf("Root2= %f - %f i \n", real, imag) ;
  }

  getch() ;
}
/*
Output 1:

Enter three co-efficients: 1  2  1
Root is real 
Root is -1.000000 

Output 2:

Enter three co-efficients: 3  4  1
Roots are real 
Roots are -0.333333 and -1.000000 


Output 3:

Enter three co-efficients: 2  2  1
Roots are imaginary 
Root1= -0.500000 + 0.500000 i 
Root2= -0.500000 - 0.500000 i 

*/


