/* Program to find GCD using Euclid's algorithm  */

#include <stdio.h>
#include <conio.h>

int  gcd(int  m , int  n) ;

void  main()
{
  int  m , n , g ;

  clrscr() ;

  printf("Enter 2 positive integers: ") ;
  scanf("%d %d",&m,&n) ;

  g=gcd(m,n) ;

  printf("GCD is: %d",g) ;
 
  getch() ;
}

int  gcd(int  m , int  n)
{
 int  r ;

 while(n>0)
 {
    r=m%n ;
    m=n ;
    n=r ;
 } 
 
 return  m ;
}

