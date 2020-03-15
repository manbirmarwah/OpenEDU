/* Pattern problem
   1
   1 2
   1 2 3
   1 2 3 4 
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
    for(j=1 ; j<=i ; j++)
      printf("%d " , j) ;         
    printf("\n") ;
  }

  getch() ;
}
/* If the pattern is fixed then variable 'n' should not be read 

Space in printf should not be given if this is the pattern:
1
12
123
1234
*/

/*
Output:

Enter the number of lines: 3
Required pattern is as follows: 
1 
1 2 
1 2 3
*/
