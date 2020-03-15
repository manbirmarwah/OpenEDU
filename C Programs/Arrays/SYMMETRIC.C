/* Matrix symmetric - Program to check whether a given matrix is symmetric or not */

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
    printf("Enter elements of the matrix row-wise: \n") ;
    for(r=0 ; r<nr ; r++)
      for(c=0 ; c<nc ; c++)
        scanf("%d" , &x[r][c]) ;

    flag=1 ;      /* assuming matrix is symmetric */
    for(r=0 ; r<nr && flag==1 ; r++)
      for(c=0 ; c<nc && flag==1 ; c++)
        if(r<c)
          if(x[r][c]!=x[c][r]) /* True if not symmetric */
	         flag=0; 

    if(flag==1)
      printf("The given matrix is symmetric");
    else
      printf("The given matrix is not symmetric");
  }
  else
    printf("The matrix is not a square matrix");

  getch();
}

/*
Output1:

Enter the number of rows and columns: 3  3
Enter elements of the matrix: 
11 1 2
1 22 3
2 3 44
The given matrix is symmetric

Output2:

Enter the number of rows and columns: 3 3
Enter elements of the matrix: 
11 1 2
1 22 3
4 3 44
The given matrix is not symmetric

Output3:

Enter the number of rows and columns: 3  4
The matrix is not a square matrix
*/

