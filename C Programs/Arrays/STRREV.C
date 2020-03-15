/* String Reverse -  Program to find reverse of given string without using string library function */

#include  <stdio.h>
#include  <conio.h>

void  reverse(char  str1[ ] , char  str2[ ]) ;
/* This function will store reverse of string 1 in string 2 */

void  main()
{
  char  str1[50] , str2[50] ;

  clrscr();

  printf("Enter the string: ") ;	 
  gets(str1) ;

  reverse(str1,str2) ;

  printf("Reversed string is: %s" , str2) ;

  getch();
}

void  reverse(char  str1[ ] , char  str2[ ])
{
  int  i , j ;

  for(i=0 ; str1[i]!='\0' ; i++) ;

  for(i=i-1 , j=0 ; i>=0 ; i-- , j++)
    str2[j]=str1[i] ;

  str2[j]='\0' ;   
}

/*
Output:

Enter the string: Sandeep Gupta
Reversed string is: atpuG peednaS
*/



