/* Demonstration Program - Parameter passing technique of call by reference */

#include  <stdio.h>
#include  <conio.h>

void  modify(int  *pa) ;

void  main()
{
  int  a=2 ;

  clrscr() ;

  printf("%d ",a) ;
  modify(&a) ;
  printf("%d ",a) ;

  getch() ;
 }

void  modify(int  *pa)
{
  *pa=*pa+2 ;
  printf("%d ",*pa) ;
}
