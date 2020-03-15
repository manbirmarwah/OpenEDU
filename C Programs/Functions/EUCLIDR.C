/* GCD Recursive - Write recursive function to calculate gcd of 2 numbers using the following Euclid's recursive algorithm:

	              gcd(n,m)		    			, if n>m
gcd(m,n) =  m			     			, if n=0
	              gcd(n,m mod n)         , otherwise
*/

#include  <stdio.h>
#include  <conio.h>

int  gcd(int  m , int  n)
{
  if(n>m)  
     return  ( gcd(n,m) ) ;
  else  if(n==0)  
     return  m  ;
  else
    return  ( gcd(n,m%n) ) ;
}

void main()
{
  int  m , n ;

  clrscr();

  printf("Enter 2 positive integers: ") ;
  scanf("%d %d", &m , &n) ;

  printf("GCD is: %d" , gcd(m,n) );
 
  getch() ;
}

/*
Output1:

Enter 2 positive integers: 18  24
GCD is: 6

Output2:

Enter 2 positive integers: 5  3
GCD is: 1
*/
