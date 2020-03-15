/* String Frequency Count - Program to count frequency of a given character in a string */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  char  str[50] , x ;
  int  i , count=0 ;

  clrscr() ;

  printf("Enter a string: ") ;
  gets(str) ;

  printf("Enter a character: ") ;
  x=getchar() ;

  for(i=0 ; str[i]!='\0' ; i++)	
    if(str[i]==x)
		count++;
 
  printf("Frequency of %c in %s is %d", x , str , count) ;
 
  getch() ;
}

/*
Output:

Enter a string: programming
Enter a character: m
Frequency of m in programming is 2
*/

