/* Pattern Problem
	 1
    121
  12321
1234321  
    ...	
*/

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  i , j , n ;

  clrscr() ;

  printf("Enter the number of lines: ") ;
  scanf("%d" , &n) ;

  printf("Required pattern is as follows: \n") ;
  for(i=1 ; i<=n ; i++)
  {
    /* Managing spaces */
    for(j=1 ; j<=n-i ; j++)
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
Give one extra space in each printf() if the pattern is:
      1
   1 2 1
1 2 3 2 1
*/

/*
Output:

Enter the number of lines: 4
Required pattern is as follows: 
      1
    121
  12321
1234321  
*/
