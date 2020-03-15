/* pow() - program to print square, cube and fourth power of a given number without doing any unnecessary calculations */

#include  <stdio.h>
#include  <conio.h>
#include  <math.h>

void main()
{
  float  x ;

  clrscr() ;

  printf("Enter a number: ") ;
  scanf("%f" , &x) ;

  printf("Square = %f \n" , pow(x,2) ) ;
  printf("Cube = %f \n" , pow(x,3) ) ;
  printf("Fourth power = %f \n" , pow(x,4) ) ;

  getch() ;
}

/*
Output:

Enter a number: 2.5
Square = 6.250000 
Cube = 15.625000 
Fourth power = 39.062500 

*/

