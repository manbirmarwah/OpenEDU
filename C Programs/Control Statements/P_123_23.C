/* Pattern problem
   ...
   1 2 3 4
   2 3 4
   3 4
   4 
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
  for(i=n ; i>=1 ; i--)
  {
    for(j=i ; j>=1 ; j--)
      printf("%d " , j) ;         
    printf("\n") ;
  }

  getch();
}

/*
Output:

Enter the number of lines: 3
Required pattern is as follows: 
3 2 1 
2 1 
1 
*/

