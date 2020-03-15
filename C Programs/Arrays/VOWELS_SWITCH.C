/* String vowel count - Program to count the number of vowels in a given string using switch statement */

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
    switch(c)
    {
      case 'a':	
      case 'e':	
      case 'i':	
      case 'o':	
      case 'u': 	v++ ;  break;
      default: break;
    }
  }

  printf("Number of vowels in %s is %d" , str , v) ;

  getch() ;
}

/*
Output:

Enter a string: Umbrella is nice
Number of vowels in Umbrella is nice is 6

*/
