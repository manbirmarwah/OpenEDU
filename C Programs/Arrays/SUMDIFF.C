/* Matrix Sum and Difference -  Program to find sum and difference of two matrices */

#include  <stdio.h>
#include  <conio.h>

void  read(int  x[ ][10] , int  nr , int  nc) ;
void  sumdiff(int  a[ ][10] , int  b[ ][10] , int  s[ ][10] , int  d[ ][10] , int  nr , int  nc) ;
void  show(int  y[ ][10] , int  nr , int  nc) ;


void main()
{
  int  a[10][10] , b[10][10] , s[10][10] , d[10][10] , nra , nca , nrb , ncb ;

  clrscr();

  printf("Enter the number of rows and columns of first matrix: ");
  scanf("%d %d", &nra , &nca) ;

  printf("Enter the number of rows and columns of second matrix: ");
  scanf("%d %d", &nrb , &ncb) ;

  if(nra==nrb && nca==ncb)
  {
    printf("Enter elements of first matrix row-wise: \n") ;
    read(a,nra,nca) ;

    printf("Enter elements of second matrix row-wise: \n") ;
    read(b,nrb,ncb) ;

    sumdiff(a,b,s,d,nra,nca);
    printf("Result of matrix addition is: \n") ;
    show(s,nra,nca) ;
    printf("Result of matrix subtraction is: \n") ;
    show(d,nra,nca) ;
  }
  else
    printf("Matrix addition and subtraction not possible.");

  getch();
}

void  read(int  x[ ][10] , int  nr , int  nc)
{
  int  r , c ;
  for(r=0 ; r<nr ; r++)
    for(c=0 ; c<nc ; c++)
      scanf("%d" , &x[r][c]) ;
}

void  sumdiff(int  a[ ][10] , int  b[ ][10] , int  s[ ][10] , int  d[ ][10] , int  nr , int  nc)
{
   int  r , c ;	
   for(r=0 ; r<nr ; r++)
     for(c=0 ; c<nc ; c++)
     {
        s[r][c]=a[r][c]+b[r][c] ;
        d[r][c]=a[r][c]-b[r][c] ;
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

Enter the number of rows and columns of first matrix: 2  2
Enter the number of rows and columns of second matrix: 2  2
Enter elements of first matrix: 
2  4
5  7
Enter elements of second matrix: 
1  2
4  3
Result of matrix addition is: 
3 6 
9 10 
Result of matrix subtraction is: 
1 2 
1 4 

Output2:
Enter the number of rows and columns of first matrix: 2  3
Enter the number of rows and columns of second matrix: 2  4
Matrix addition and subtraction not possible.
*/

