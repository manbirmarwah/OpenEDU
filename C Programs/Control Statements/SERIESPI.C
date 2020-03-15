/* PI 's  value - Program to find value of pi using the series :  pi^2 / 6  =  1/1^2 + 1/2^2 +.....  + 1/1000^2 */

#include  <stdio.h>
#include  <conio.h>
#include  <math.h>  

void main()
{
  float  s=0 , pi , i ;

  clrscr() ;
  for(i=1 ; i<=1000 ; i++)
   s=s+1/(i*i) ;  /* Parentheses compulsory */

  pi=sqrt(s*6) ;

  printf("The value of pi is %f" , pi) ;

  getch() ;
}


/*
Output :

The value of pi is 3.140638
*/

