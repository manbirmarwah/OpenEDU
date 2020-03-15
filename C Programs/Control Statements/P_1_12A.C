/* Pattern Problem 
       1
     1 2 A
   1 2 3 A B
 1 2 3 4 A B C
*/

#include  <stdio.h>
#include  <conio.h>
void  main()
{
  int  i , j ;

  clrscr();
  printf("Required Pattern is as follows:\n");
  for(i=1 ; i<=4 ; i++)
  {
    /* Managing spaces */
    for(j=1 ; j<=4-i ; j++)
      printf("  ") ;

    /* Prinitng digits*/
    for(j=1 ; j<=i ; j++) 
      printf("%d " , j) ;

    /* Printing alphabets*/
    for(j=1 ; j<i ; j++) 
      printf("%c " , j+64) ;

    printf("\n") ;
  }

  getch() ;
}

/*
Output:

Required Pattern is as follows:
      1 
    1 2 A 
  1 2 3 A B 
1 2 3 4 A B C 
*/


