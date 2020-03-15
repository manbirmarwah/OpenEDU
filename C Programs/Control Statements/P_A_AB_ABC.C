/* Pattern problem
   A
   A B
   A B C
   A B C D
   A B C D E 
*/

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  i , j , n ;

  clrscr() ;

  printf("Required pattern is as follows: \n") ;
  for(i=1 ; i<=5 ; i++)
  {
    for(j=1 ; j<=i ; j++)
      printf("%c " , j+64) ;         
    printf("\n") ;
  }

  getch();
}

/*
Output:

Required pattern is as follows: 
A 
A B 
A B C 
A B C D 
A B C D E 
*/
