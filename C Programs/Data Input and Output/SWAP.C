/* swap - program to swap values of two integers without using a temporary variable */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  x , y ;

  clrscr() ;

  printf("Enter two integers: ") ;
  scanf("%d %d" , &x , &y) ;

  printf("x=%d y=%d \n" , x , y) ;

  x=x+y ;
  y=x-y ;
  x=x-y ;

  printf("After swapping: \n") ;
  printf("x=%d y=%d" , x , y) ;

  getch() ;
}

/*
Output:

Enter two integers: 5  8
x=5 y=8 
After swapping: 
x=8 y=5

*/

