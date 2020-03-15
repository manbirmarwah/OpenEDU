/* Pattern Problem
	  *
     *  *
   *  *  *
     *  *
       *
*/

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  i , j ;

  clrscr() ;

  printf("Required pattern is as follows: \n") ;

  for(i=1 ; i<=3 ; i++)
  {
    /* Managing spaces */
    for(j=1 ; j<=3-i ; j++)
      printf(" ") ;

     /* Printing from left to Centre */        
    for(j=1 ; j<=i ; j++)
      printf("* ") ;

    printf("\n") ;
  }

  for(i=3-1 ; i>=1 ; i--)
  {
    /* Managing spaces */
    for(j=3-i ; j>=1 ; j--)
      printf(" ") ;

     /* Printing from left to Centre */        
    for(j=1 ; j<=i ; j++)
      printf("* ") ;

    printf("\n") ;
  }

  getch();
}

/*
Output:

Required pattern is as follows: 
      *
    *  *
  *  *  *
    *  *
      *

*/


