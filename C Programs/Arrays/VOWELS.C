/* String vowel count - Program to count the number of vowels in a given string */

/* Assume y is not a vowel*/
#include  <stdio.h>
#include  <conio.h>
#include  <ctype.h>
void main()
{
  char  str[50] , c ;
  int  i , v=0 ;

  clrscr() ;

  printf("Enter a string: ") ;
  gets(str) ;

  for(i=0 ; str[i]!='\0' ; i++)
  {
    c=tolower(str[i]) ;
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
      v++ ;
  }

  printf("Number of vowels in %s is %d" , str , v) ;

  getch() ;
}

/*
Output:

Enter a string: Umbrella is nice
Number of vowels in Umbrella is nice is 6

*/
