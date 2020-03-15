/* Structure - Addition of two points
A point on the two dimensional plane can be represented by two numbers: an x co-ordinate and y co-ordinate. For eg (2,3) represents a point 2 units to the right of the origin along the x axis and 3 units up the y axis. The sum of the two points can be defined as a new point whose x co-ordinate is the sum of the x co-ordinates of the two points and whose y co-ordinate is the sum of the y co-ordinates of the two points. 

Write a program that uses a structure called point to model a point. Define 3 points and let the user input values for two of them. Then set the third point equal to the sum of other two and display the values of the new point. */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  struct point
  {
    int  x , y ;
  } ;
  struct  point  p1 , p2 , p3 ;
 
  clrscr();

  printf("Enter x and y co-ordinate for point 1: ") ;
  scanf("%d %d", &p1.x , &p1.y) ;

  printf("Enter x and y co-ordinate for point 2: ") ;
  scanf("%d %d" , &p2.x , &p2.y) ;

  p3.x=p1.x+p2.x;
  p3.y=p1.y+p2.y;

  printf("The new point is (%d,%d)" , p3.x , p3.y) ;

  getch() ;
}

/*
Output:

Enter x and y co-ordinate for point 1: 2  6
Enter x and y co-ordinate for point 2: 4  1
The new point is (6,7)
*/

