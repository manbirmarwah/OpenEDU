/* Binomial Coefficient - Write a function to find factorial of a number. Using this function,  find value of binomial co-efficient (B) where B = n! / r! * (n-r)!  where n and r are natural numbers. */

#include  <stdio.h>
#include  <conio.h>

long  fact(int  n) ;

void main()
{
  int  n , r ;
  long  f1 , f2 , f3 , b ;    

  clrscr() ;

  printf("Enter natural numbers n and r (n>r): ") ;
  scanf("%d %d" , &n , &r) ;

  f1=fact(n) ;
  f2=fact(r) ;
  f3=fact(n-r) ;
  b=f1/(f2*f3) ;

  printf("Binomial Coefficient = %ld" , b) ; 

  getch() ;
}

long  fact(int  n)
{
  int  i;
  long  f=1 ;

  for(i=1 ; i<=n ; i++)
	f=f*i ;

  return  f ;
}


/*
Output:

Enter natural numbers n and r (n>r): 9  5
Binomial Coefficient = 126
*/