/* Pattern Problem
	 1
    121
  12321
1234321
  12321
    121
      1
*/

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  i , j ;

  clrscr() ;

  printf("Required pattern is as follows: \n") ;
  for(i=1 ; i<=4 ; i++)
  {
    /* Managing spaces */
    for(j=1 ; j<=4-i ; j++)
      printf(" ") ;

     /* Printing from left to Centre */        
    for(j=1 ; j<=i ; j++)
      printf("%d" , j) ;

    /* Printing to the right of Centre */        
    for(j=i-1 ; j>=1 ; j--)
      printf("%d" , j) ; 

    printf("\n") ;
  }

  for(i=4-1 ; i>=1 ; i--)
  {
    /* Managing spaces */
    for(j=4-i ; j>=1 ; j--)
      printf(" ") ;

     /* Printing from left to Centre */        
    for(j=1 ; j<=i ; j++)
      printf("%d" , j) ;

    /* Printing to the right of Centre */        
    for(j=i-1 ; j>=1 ; j--)
      printf("%d" , j) ; 

    printf("\n") ;
  }

  getch();
}

/*
Output:

Required pattern is as follows: 
   1
  121
 12321
1234321
 12321
  121
   1
*/
