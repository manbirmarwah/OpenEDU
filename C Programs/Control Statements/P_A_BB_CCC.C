/* Pattern Problem
      A
    B  B
  C  C  C
D  D  D  D    
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
      printf("%c ",i+64) ;

    printf("\n") ;
  }

  getch();
}

/*
Output:

Enter the number of lines: 4
Required pattern is as follows:
      A
    B  B
  C  C  C
D  D  D  D    
      
*/




