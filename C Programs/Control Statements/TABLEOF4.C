/* Table of 4 - Program to print 4 times table */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int i , n ;
  clrscr() ;

  printf("Enter the limit: ") ;
  scanf("%d" , &n) ;

  printf("Four times table is as shown: \n") ;
  for(i=1 ; i<=n ; i++)
    printf("4 * %d = %d \n" , i , 4*i ) ;

  getch() ;
}

/*
Output :

Enter the limit: 3
Four times table is as shown: 
4 * 1 = 4 
4 * 2 = 8 
4 * 3 = 12
*/