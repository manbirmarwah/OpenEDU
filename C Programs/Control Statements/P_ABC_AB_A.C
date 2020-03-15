/* Pattern Problem
A B C D
  A B C
    A B
      A
*/

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  i , j ;

  clrscr() ;

  printf("Required pattern is as follows: \n") ;

  for(i=4 ; i>=1 ; i--)
  {
    /* Managing spaces */
    for(j=4-i ; j>=1 ; j--)
      printf("  ") ;

     /* Printing from left to Centre */        
    for(j=1 ; j<=i ; j++)
      printf("%c " , j+64) ;

    printf("\n") ;
  }

  getch();
}

/*
Output:

Required pattern is as follows: 
A B C D 
  A B C 
    A B 
      A 
*/




