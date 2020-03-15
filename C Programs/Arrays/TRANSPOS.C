/* Matrix transpose - Program to find transpose of a matrix m*n using functions to
1) Read elements of matrix		
2) find transpose	
3) Display elements of matrix
4) find transpose using single matrix. 
May 2013 */

#include  <stdio.h>
#include  <conio.h>

void  read(int  x[ ][10] , int  nr , int  nc) ;
void  transpose(int  x[ ][10] , int  y[ ][10] , int  nr , int  nc) ;
void  show(int  y[ ][10] , int  nr , int  nc) ;
void  singletranspose(int  x[ ][10] , int  nr , int  nc) ;

void main()
{
  int  x[10][10] , y[10][10] , m , n ;

  clrscr();
 
  printf("Enter the number of rows and columns: ");
  scanf("%d %d", &m , &n) ;
  printf("Enter elements of the matrix row-wise:\n") ;
  read(x , m , n) ;
  transpose(x , y , m , n) ;
  printf("Transpose of given matrix is:\n") ;
  show(y,n,m) ;

  if(m==n)
  {
    singletranspose(x,m,n);
    printf("Transpose using single matrix is:\n");
    show(x,n,m);
  }
  else
    printf("The matrix is not a square matrix");

  getch();
}

void  read(int  x[ ][10] , int  nr , int  nc)
{
 int  r , c ;
 for(r=0 ; r<nr ; r++)
   for(c=0 ; c<nc ; c++)
      scanf("%d" , &x[r][c]) ;
}

void transpose(int  x[ ][10] , int  y[ ][10] , int  nr , int  nc)
{
 int  r , c ;
 for(r=0 ; r<nr ; r++)
   for(c=0 ; c<nc ; c++)
     y[c][r]=x[r][c] ;
}

void  singletranspose(int  x[ ][10] , int  nr , int  nc)
{
  int  r , c , t ;
  for(r=0 ; r<nr ; r++)
    for(c=0 ; c<nc ; c++)
      if(r<c)
      {
	     t=x[r][c];
	     x[r][c]=x[c][r];
	     x[c][r]=t;
	   }
}

void  show(int  y[ ][10] , int  nr , int  nc)
{
 int  r , c ;
 for(r=0 ; r<nr ; r++)
 {
   for(c=0 ; c<nc ; c++)
      printf("%d " , y[r][c]) ;
   printf("\n") ;
  }
}

/*
Output1:

Enter the number of rows and columns: 3  3
Enter elements of the matrix:
11 2 4
3 22 6
5 7 44
Transpose of given matrix is:
11 3 5 
2 22 7 
4 6 44 
Transpose using single matrix is:
11 3 5 
2 22 7 
4 6 44 

Output2:

Enter the number of rows and columns: 2  3
Enter elements of the matrix:
2 4 6
3 5 7
Transpose of given matrix is:
2 3 
4 5 
6 7 
The matrix is not a square matrix
*/

