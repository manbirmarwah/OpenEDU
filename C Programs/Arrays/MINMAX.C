/* Matrix minimum and maximum  - Program to find minimum and maximum of a given matrix */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  x[10][10] , nr , nc , r , c , min , max ;

  clrscr() ;

  printf("Enter the number of rows and columns: ") ;
  scanf("%d %d", &nr , &nc) ;

  printf("Enter elements of the matrix row-wise: \n") ;
  for(r=0 ; r<nr ; r++)
    for(c=0 ; c<nc ; c++)
        scanf("%d" , &x[r][c]) ;
  
  /* assuming first element to be minimum as well as maximum */
  min=max=x[0][0]; 

  for(r=0 ; r<nr ; r++)
    for(c=0 ; c<nc ; c++)
    {
      if(x[r][c]<min)
	    min=x[r][c];
      if(x[r][c]>max)
	    max=x[r][c];
    }	

  printf("Minimum  is  %d \n" , min) ;
  printf("Maximum is  %d" , max) ;
  getch();
}

/*
Output:

Enter the number of rows and columns: 2  3
Enter elements of the matrix: 
2  5  1
8  6  4
Minimum  is  1 
Maximum is  8
*/

