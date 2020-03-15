/* String concatenate and length -  Program to concatenate two strings and find string length using functions */

#include  <stdio.h>
#include  <conio.h>

void  concatenate(char  str1[ ] , char  str2[ ]) ;
int  stringlength(char  str[ ]) ;

void main()
{
  char  str1[50] , str2[50] , str[50] ;

  clrscr();
  
  printf("Performing string concatenation \n") ;
  printf("Enter two strings:\n") ;
  gets(str1) ;
  gets(str2) ;
  concatenate(str1,str2) ;
  printf("Concatenated string is: ") ;
  puts(str1);

  printf("\nFinding string length \n") ;
  printf("Enter a string: ") ;
  gets(str) ;
  printf("String length is: %d" , stringlength(str) ) ;

  getch();
}

void  concatenate(char  str1[ ] , char  str2[ ])
{
  int  i , j ;

  for(i=0 ; str1[i]!='\0' ; i++) ; 

  for(j=0 ; str2[j]!='\0' ; j++ , i++) 
    str1[i]=str2[j] ;

  str1[i]='\0' ;   
}

int  stringlength(char  str[ ])
{
  int  i ;

  for(i=0 ; str[i]!='\0' ; i++) ; 

  return  i ;
}

/*
Output:

Performing string concatenation 
Enter two strings:
New
York
Concatenated string is: NewYork

Finding string length 
Enter a string: Apple
String length is: 5
*/

