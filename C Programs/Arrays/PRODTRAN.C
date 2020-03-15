/* Matrix multiplication and Transpose - Program to perform matrix multiplication and transpose - May 2013 */

#include  <stdio.h>
#include  <conio.h>

void  read(int  x[ ][10] , int  nr , int  nc) ;
void  multiply(int  a[ ][10] , int  b[ ][10] , int  c[ ][10] , int  l , int  m , int  n) ;
void  transpose(int  x[ ][10] , int  y[ ][10] , int  nr , int  nc) ;
void  show(int  y[ ][10] , int  nr , int  nc) ;


void main()
{
  int  a[10][10] , b[10][10] , c[10][10] , nra , nca , nrb , ncb ;
  int  x[10][10] , y[10][10] , m , n ;

  clrscr();

  printf("Performing Matrix Multiplication \n \n") ;
  printf("Enter the number of rows and columns of first matrix: ") ;
  scanf("%d %d", &nra , &nca) ;

  printf("Enter the number of rows and columns of second matrix: ") ;
  scanf("%d %d", &nrb , &ncb) ;

  if(nca==nrb)
  {
    printf("Enter elements of first matrix row-wise: \n") ;
    read(a,nra,nca) ;

    printf("Enter elements of second matrix row-wise: \n") ;
    read(b,nrb,ncb) ;

    multiply(a,b,c,nra,nca,ncb);
    printf("Result of matrix multiplication is: \n") ;
    show(c,nra,ncb) ;
  }
  else
    printf("Matrices A and B do not conform to multiplication") ;

  printf("\nPerforming Matrix transpose \n \n") ;
  printf("Enter the number of rows and columns: ") ;
  scanf("%d %d", &m , &n) ;
  printf("Enter elements of the matrix row-wise:\n") ;
  read(x , m , n) ;
  transpose(x , y , m , n) ;
  printf("Transpose of given matrix is:\n") ;
  show(y,n,m) ;

  getch() ;
}

void  read(int  x[ ][10] , int  nr , int  nc)
{
 int  r , c ;
 for(r=0 ; r<nr ; r++)
   for(c=0 ; c<nc ; c++)
      scanf("%d" , &x[r][c]) ;
}

void  multiply(int  a[ ][10] , int  b[ ][10] , int  c[ ][10] , int  l , int  m , int  n)
{
  int  i , j , k ;
  for(i=0 ; i<l ; i++)
    for(j=0 ; j<n ; j++)
    {
      c[i][j]=0 ;
      for(k=0 ; k<m ; k++)
        c[i][j]=c[i][j]+a[i][k]*b[k][j] ;
     }
}

void transpose(int  x[ ][10] , int  y[ ][10] , int  nr , int  nc)
{
 int  r , c ;
 for(r=0 ; r<nr ; r++)
   for(c=0 ; c<nc ; c++)
     y[c][r]=x[r][c] ;
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
Output:

Performing Matrix Multiplication 
 
Enter the number of rows and columns of first matrix: 2  3
Enter the number of rows and columns of second matrix: 3  2
Enter elements of first matrix: 
1 2 4
3 5 6
Enter elements of second matrix: 
2 5
1 6
4 3
Result of matrix multiplication is: 
20 29 
35 63 

Performing Matrix transpose 
 
Enter the number of rows and columns: 2 3
Enter elements of the matrix:
2 4 6
3 5 7
Transpose of given matrix is:
2 3 
4 5 
6 7 

*/

