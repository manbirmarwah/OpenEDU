/* Month in words - Program to read month number as input and display the month in words. */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  m ;

  clrscr() ;

  printf("Enter a month number: ") ;
  scanf("%d" , &m) ;

  printf("Month in words is: ") ;

  switch(m)
  {
     case 1: printf("January") ;
	           break ;
     case 2: printf("February") ;
	           break ;
     case 3: printf("March") ;
	           break ;
     case 4: printf("April") ;
	           break ;
     case 5: printf("May") ;
	           break ;
     case 6: printf("June") ;
	           break ;
     case 7: printf("July") ;
	           break ;
     case 8: printf("August") ;
	           break ;
     case 9: printf("September") ;
	           break ;
     case 10: printf("October") ;
	             break ;
     case 11: printf("November") ;
	             break ;
     case 12: printf("December") ;
	             break ;
     default: printf("\nWrong Input") ;
	            break ;
  }

  getch() ;
}

/*
Output 1:

Enter a month number: 7
Month in words is: July

Output 2:
Enter a month number: 13
Month in words is: 
Wrong Input
*/
