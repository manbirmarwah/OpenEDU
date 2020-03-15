/* String Copying -  Program to copy one string into another using a function */

#include  <stdio.h>
#include  <conio.h>

void  copy(char  str1[ ] , char  str2[ ]) ;
/* This function will copy contents of string 2 in string 1 */

void main()
{
  char  str1[50] , str2[50] ;

  clrscr();

  printf("Enter source string: ") ;	 
  gets(str2) ;

  copy(str1,str2) ;

  printf("Copied string: %s" , str1) ;

  getch();
}

void  copy(char  str1[ ] , char  str2[ ])
{
  int  i , j ;

  for(i=0 , j=0 ; str2[i]!='\0' ; j++ , i++)
    str1[j]=str2[i] ;

  str1[j]='\0' ;   
}

/*
Output:

Enter source string: SPA sem 2
Copied string: SPA sem 2
*/


