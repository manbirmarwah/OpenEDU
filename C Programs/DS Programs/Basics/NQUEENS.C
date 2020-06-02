/* Queens problem - Program to find solution to n queens problem */

#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

void  nqueens(int  r , int  n , int  column[ ]) ;
int  place(int  r , int  c , int  column[ ]) ;

void  main()
{
  int  n ;
  int  column[50] ;

  clrscr();

  printf("Enter the number of queens: ") ;
  scanf("%d" , &n) ;

  nqueens(1,n,column) ;  /* placing queen number 1 in row number 1 */

  getch() ;
}

void  nqueens(int  r , int  n , int  column[ ])
{
  int  i , c ;

  for(c=1 ; c<=n ; c++)
    if(place(r,c,column))
    {
      /* placing queen no. r in row r and column c */
      column[r]=c ;

      if(r==n)   /* all queens are placed */
      {
	   for(i=1 ; i<=n ; i++)   /* displaying solution */
	     printf("Queen no %d is placed in row no %d and column no %d \n" , i , i , column[i] ) ;
	   getch() ;

	   exit(1) ;   /* Dont write return */
      }
      else
	   nqueens(r+1,n,column) ;   /* placing the next queen */
    }
}

int  place(int  r , int  c , int  column[ ])
{
  int  j ;

  for(j=1 ; j<=r-1 ; j++)

     if( (column[j]==c) || ( (abs(column[j]-c)) == (abs(j-r)) ) )

		return  0 ;

  return  1;
}

/*
condition 1 is true if 2 queens are in the same column
condition 2 is true if 2 queens are in the same diagnol
*/
