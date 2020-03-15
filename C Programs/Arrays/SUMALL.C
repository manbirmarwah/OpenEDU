/* Matrix Sum of all elements - Program to find sum of all elements of a given matrix */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  x[10][10] , nr , nc , r , c , sum=0 ;

  clrscr() ;

  printf("Enter the number of rows and columns: ") ;
  scanf("%d %d", &nr , &nc) ;

  printf("Enter elements of the matrix row-wise: \n") ;
    for(r=0 ; r<nr ; r++)
      for(c=0 ; c<nc ; c++)
      {
        scanf("%d" , &x[r][c]) ;
        sum = sum + x[r][c] ;
      }
  printf("The sum of all matrix elements is %d" , sum) ;

  getch() ;
}

/*
Output:

Enter the number of rows and columns: 2 3
Enter elements of the matrix row-wise: 
2 1 4
5 8 6
The sum of all matrix elements is 26
*/

