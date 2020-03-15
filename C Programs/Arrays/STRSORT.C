/* String Sort - Program that will read a string and rewrite it in alphabetical order. For example, the word  'string' should be written as 'ginrst' */

#include  <stdio.h>
#include  <conio.h>
#include  <ctype.h>
#include  <string.h>

void main()
{
  char  x[50] , temp ;
  int  i , j , n ;

  clrscr();

  printf("Enter a string: ") ; 
  gets(x) ;

  n=strlen(x) ;
 
  for(i=0 ; i<n-1 ; i++)
    for(j=0 ; j<n-1-i ; j++)
       if( tolower(x[j])  >  tolower(x[j+1]) )
       {
       		temp=x[j] ;
       		x[j]=x[j+1] ;
       		x[j+1]=temp ;
       }

  printf("Given string in alphabetical order is %s " , x) ;

  getch();
}

/*
Output:

Enter a string: Programming
Given string in alphabetical order is aggimmnoPrr 
*/

/* The above output (look at P) shows that our logic of sorting is NOT CASE SENSITIVE */