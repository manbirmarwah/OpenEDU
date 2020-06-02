/* Program to find x raise to n where x and n both are integers greater than or equal to zero */

#include  <stdio.h>
#include  <conio.h>

int  exp(int  x , int  n) ;

void  main()
{
  int  x , n , p ;

  clrscr() ;

  printf("Enter 2 non negative integers: ") ;
  scanf("%d %d",&x,&n) ;

  p=exp(x,n) ;

  printf("%d raise to %d is: %d",x,n,p) ;
 
  getch() ;
}

int  exp(int  x , int  n)
{
  if(n==0)
    return  1 ;
  if(n==1)
    return  x ;
  if(n%2==0) 
    return exp(x*x , n/2) ;
  else
    return exp(x*x , n/2) * x ;
}

