/* String remove comma - Program that reads a number greater than or equal to 1000 from the user. The user enters a comma in the input. Print the number without the comma */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  i ;
  char  n[20] ;

  clrscr() ;

  printf("Enter a number greater than or equal to 1000: ") ;
  gets(n) ;

  printf("Number without comma is:") ;
  for(i=0 ; n[i]!='\0' ; i++)
    if(n[i] != ',')
      putchar(n[i]) ;

  getch();
}

/*
Output:

Enter a number greater than or equal to 1000: 2,46,798
Number without comma is:246798
*/

