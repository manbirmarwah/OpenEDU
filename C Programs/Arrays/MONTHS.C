/* String - Program which reads month number and displays the same in words. (Use two dimensional array) */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  m ;
  char  x[12][10] = {"January"  ,  "February"  ,  "March"  ,  "April"  ,  "May"  ,  "June"  ,   "July"  ,  "August"  ,  "September"  ,  "October", 
                               "November"  ,  "December" } ;

  clrscr();

  printf("Enter the month number: ") ;
  scanf("%d" , &m) ;

  printf("Month in words is: %s" , x[m-1]) ;

  getch();
}

/*
Output:

Enter the month number: 7
Month in words is: July
*/



 
