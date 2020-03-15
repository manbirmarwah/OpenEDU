/* Pattern Problem
	       1
         2 2
      3 3 3
   4 4 4 4  
5 5 5 5 5	
*/

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  i , j ;

  clrscr() ;

  printf("Required pattern is as follows: \n") ;
  for(i=1 ; i<=5 ; i++)
  {
    /* Managing spaces */
    for(j=1 ; j<=5-i ; j++)
      printf("  ") ;

     /* Printing from left to Centre */        
    for(j=1 ; j<=i ; j++)
      printf("%d " , i) ;

    printf("\n") ;
  }

  getch();
}

/*
Output:

Required pattern is as follows: 
            1
         2 2
      3 3 3
   4 4 4 4  
5 5 5 5 5
*/
