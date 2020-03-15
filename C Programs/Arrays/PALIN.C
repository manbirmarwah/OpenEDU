/* String Palindrome - Program to check whether a given string is a palindrome or not - May 2013*/

#include  <stdio.h>
#include  <conio.h>
#include  <ctype.h>
#include  <string.h>

void main()
{
  char  str[50] ;
  int i , j , length , flag ;

  clrscr() ;

  printf("Enter a string: ") ;
  gets(str) ;

  length=strlen(str) ;

  flag=1 ;   /* assuming that the string is a palindrome */
  i=0 ;
  j=length-1 ;
  while(i<length/2)
    if( tolower(str[i]) == tolower(str[j]) )
    {
       i++ ;
       j-- ;
    }
   else
   {
      flag=0 ;
      break ;
   }

  if(flag==1)
    printf("String %s is a palindrome" , str) ;
  else
    printf("String %s is not a palindrome" , str) ;  getch() ;
}

/*
Output1:

Enter a string: Maam
String Maam is a palindrome

Output2:

Enter a string: Madam
String Madam is a palindrome

Output3:

Enter a string: apple
String apple is not a palindrome
*/
