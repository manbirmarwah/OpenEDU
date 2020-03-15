/* Pattern Problem
          1
        2 3 2
      3 4 5 4 3
	 4 5 6 7 6 5 4
		
*/

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  i , j , k , n ;

  clrscr() ;

  printf("Required pattern is as follows: \n") ;
  for(i=1 ; i<=4 ; i++)
  {
    /* Managing spaces */
    for(j=1 ; j<=4-i ; j++)
      printf("  ") ;

     /* Printing from left to Centre */        
    for(k=1 , j=i ; k<=i ; k++ , j++)
      printf("%d " , j) ;

    /* Printing to the right of Centre */        
    for(k=1 , j=j-2 ; k<=i-1 ; k++ , j--)
      printf("%d " , j) ; 

    printf("\n") ;
  }

  getch();
}

/*
Output:

Required pattern is as follows: 
      1 
    2 3 2 
  3 4 5 4 3 
4 5 6 7 6 5 4 

*/




