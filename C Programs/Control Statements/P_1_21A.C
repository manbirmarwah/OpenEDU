/* Pattern Problem 
    1
   21A
  321AB
 4321ABC
54321ABCD
 */

#include  <stdio.h>
#include  <conio.h>
void main()
{
  int  i , j ;

  clrscr();
  printf("Required Pattern is as follows:\n");
  for(i=1;i<=5;i++)
  {
    /* Managing spaces */
    for(j=1 ; j<=5-i ; j++)
      printf(" ") ;

    /* Prinitng digits*/
    for(j=i ; j>=1 ; j--) 
      printf("%d" , j) ;

    /* Printing alphabets*/
    for(j=1 ; j<i ; j++) 
      printf("%c" , j+64) ;

    printf("\n") ;
  }

  getch() ;
}

/*
Output:

Required Pattern is as follows:
    1
   21A
  321AB
 4321ABC
54321ABCD

*/



