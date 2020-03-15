/* Leap year - Program to check whether a given year is a leap year. Centennial years are leap years only when they are divisible by 400 */

/* The program can give one of the following four outputs:
   1-- not a leap year
   2-- leap year
   3-- centennial but not a leap year
   4-- centennial and a leap year	*/

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  y ;

  clrscr() ;

  printf("Enter any year: ") ;
  scanf("%d" , &y) ;

  if(y%4 == 0) 
  {
    if(y%100 != 0)   /* checks whether y is not centennial */
      printf("%d is a leap year \n" , y);
    else
      if( y%400 == 0)  /* checks whether centennial year is divisible by 400 */
        printf("%d is a centennial leap year \n" , y);
      else
        printf("%d is a centennial but not a leap year \n" , y);
  }
  else
    printf("%d is not a leap year \n" , y);

  getch();
}

/*
4 Outputs:

Enter any year: 2012
2012 is a leap year 

Enter any year: 2013
2013 is not a leap year 

Enter any year: 2000
2000 is a centennial leap year 

Enter any year: 1900
1900 is a centennial but not a leap year 

*/

