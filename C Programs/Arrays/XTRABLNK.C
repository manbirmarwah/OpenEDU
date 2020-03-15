/* String - Extra blank Spaces -  Program to remove extra blank spaces from a string. For example , i/p: HellobbbWorld , o/p: HellobWorld , b - blank space */

#include  <stdio.h>
#include  <conio.h>

void  main()
{
  char  str[50] ;
  int  i ;
  clrscr();
  printf("Enter a line: \n") ;
  gets(str)  ;

  printf("Modified line is: \n") ;

  for(i=0 ; str[i]!='\0' ; i++)
    if(str[i]!=' ')
      putchar(str[i]) ;
    else
    {
       while(str[i]==' ') /* Skipping spaces */
	     i++ ;
       putchar(' ') ; 
       putchar(str[i]) ;
    }
  getch() ;
}
/* This program will not remove extra tabs since a tab is '\t' and we are checking only for blank space ( ' ' ) */

/*
Output:
Enter a line: 
The         boy ate     the apple
Modified line is: 
The boy ate the apple
*/