/* Demonstration Program  - Program to demonstrate parameter passing technique of call by value */

#include  <stdio.h>
#include  <conio.h>

void  modify(int  a) ;

void  main()
{
  int  a=2 ;

  clrscr() ;

  printf("%d ",a) ;
  modify(a) ;
  printf("%d ",a) ;

  getch() ;
}

void  modify(int  a)
{
  a=a+2 ;
  printf("%d ",a) ;
}