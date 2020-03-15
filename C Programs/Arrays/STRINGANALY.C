/* String Analysis - Program to count the number of whitespaces , digits , alphabets and other characters in a given string */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  char  str[50] , c ;
  int  i , letter=0 , digit=0 , white=0 , other=0 ;

  clrscr();

  printf("Enter a string: ") ; 
  gets(str) ;

  for(i=0 ; str[i]!='\0' ; i++)
  {    
    c=str[i] ;

    if( c>='0' && c<='9' )
     	digit++ ;
    else if( (c>='A' && c<='Z') || (c>='a' && c<='z') )
     	letter++ ;
    else if(c==' ' || c=='\t')
     	white++ ;
    else
     	other++ ;
  }

  printf("There are %d alphabets in the given string \n" , letter) ;
  printf("There are %d digits in the given string \n" , digit) ;
  printf("There are %d whitespace characters in the given string \n" , white) ;
  printf("There are %d other characters in the given string" , other) ;

  getch();
 }
/*
Output:

Enter a string: ab#2	@45 DM
There are 4 alphabets in the given string 
There are 3 digits in the given string 
There are 2 whitespace characters in the given string 
There are 2 other characters in the given string
*/
/* There is a tab between 2 and @ in the above output */

