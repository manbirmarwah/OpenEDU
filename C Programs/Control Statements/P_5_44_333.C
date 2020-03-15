/* Pattern problem
   5
   4 4
   3 3 3
   2 2 2 2
   1 1 1 1 1 
*/

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  i , j ;

  clrscr() ;

  printf("Required pattern is as follows: \n") ;
  for(i=5 ; i>=1 ; i--)
  {
    for(j=5 ; j>=i ; j--)
      printf("%d " , i) ;   
      
    printf("\n") ;
  }

 getch() ;
}

/*
Output:

Required pattern is as follows: 
5 
4 4 
3 3 3 
2 2 2 2 
1 1 1 1 1 


*/