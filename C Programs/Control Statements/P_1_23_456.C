/* Pattern problem
   1
   2 3
   4 5 6
   7 8 9 10 
   ...	
*/

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  i , j , k ;

  clrscr() ;

  printf("Required pattern is as follows: \n") ;
  k=1 ;
  for(i=1 ; i<=4 ; i++)
  {
    for(j=1 ; j<=i ; j++)
      printf("%d " , k++) ;         
    printf("\n") ;
  }

  getch() ;
}

/*
Output:

Required pattern is as follows: 
1 
2 3 
4 5 6 
7 8 9 10 
*/
