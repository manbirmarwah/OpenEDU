/* Matrix Diagonal - Program to check whether a given matrix is diagonal matrix */

/*  A diagonal matrix is that square matrix whose diagonal elements from upper left to lower right are non-zero and all other elements are zero. For example,
2  0  0
0  4  0
0  0  6  
*/

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  x[10][10] , nr , nc , r , c , flag ;

  clrscr() ;

  printf("Enter the number of rows and columns: ") ;
  scanf("%d %d", &nr , &nc) ;

  if(nr==nc)  		/* checking for square matrix */
  {
    printf("Enter elements of the matrix: \n") ;
    for(r=0 ; r<nr ; r++)
      for(c=0 ; c<nc ; c++)
        scanf("%d" , &x[r][c]) ;

    flag=1 ;
    for(r=0 ; r<nr ; r++)
      for(c=0 ; c<nc ; c++)
        if(r==c) /* true for diagonal elements */
        {
	       if(x[r][c]==0)
	         flag=0;
        }
        else
        {
	       if(x[r][c]!=0)
	         flag=0;
        }

    if(flag==1)
      printf("The matrix is diagonal") ;
    else
      printf("The matrix is not diagonal") ; 
  }
  else
    printf("The matrix is not a sqaure matrix") ;

  getch() ;
}

/*
Output1:

Enter the number of rows and columns: 3 3
Enter elements of the matrix: 
11 0 0
0 22 0
0 0 44
The matrix is diagonal

Output2:

Enter the number of rows and columns: 3 3
Enter elements of the matrix: 
11 0 2
0 22 0
0 0 44
The matrix is not diagonal

Output3:

Enter the number of rows and columns: 3  3
Enter elements of the matrix: 
0 0 0
0 9 0
0 0 8
The matrix is not diagonal
*/

