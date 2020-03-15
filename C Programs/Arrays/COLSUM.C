/* Matrix Column Sum - Program to find sum of column elements of all the columns of a given matrix */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  x[10][10] , nr , nc , r , c , sum ;

  clrscr() ;

  printf("Enter the number of rows and columns: ") ;
  scanf("%d %d", &nr , &nc) ;

  printf("Enter elements of the matrix row-wise: \n") ;
  for(r=0 ; r<nr ; r++)
    for(c=0 ; c<nc ; c++)
        scanf("%d" , &x[r][c]) ;
  
  for(c=0 ; c<nc ; c++)
  {
	sum=0;
    for(r=0 ; r<nr ; r++)
      sum=sum+x[r][c];
    printf("Sum of elements of column no %d is %d \n" , c , sum) ;
  }

  getch();
}

/*
Output:

Enter the number of rows and columns: 3  3
Enter elements of the matrix: 
1  5  8
2  3  4
6  7  9
Sum of elements of column no 0 is 9 
Sum of elements of column no 1 is 15 
Sum of elements of column no 2 is 21 
*/

