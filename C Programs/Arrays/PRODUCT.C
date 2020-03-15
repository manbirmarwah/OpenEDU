/* Matrix multiplication - Develop a function that takes as arguments 3 matrices a , b , c and 3 integer variables l,m,n. Calculate product of a and b and store the result in c. Also write a main routine which will test whether the input matrices a and b are conformal to multiplication - May 2013 */

#include  <stdio.h>
#include  <conio.h>

void  read(int  x[ ][10] , int  nr , int  nc) ;
void  multiply(int  a[ ][10] , int  b[ ][10] , int  c[ ][10] , int  l , int  m , int  n) ;
void  show(int  y[ ][10] , int  nr , int  nc) ;


void main()
{
  int  a[10][10] , b[10][10] , c[10][10] , nra , nca , nrb , ncb ;

  clrscr();

  printf("Enter the number of rows and columns of first matrix: ");
  scanf("%d %d", &nra , &nca) ;

  printf("Enter the number of rows and columns of second matrix: ");
  scanf("%d %d", &nrb , &ncb) ;

  if(nca==nrb)
  {
    printf("Enter elements of first matrix row-wise: \n");
    read(a,nra,nca);

    printf("Enter elements of second matrix row-wise: \n");
    read(b,nrb,ncb);

    multiply(a,b,c,nra,nca,ncb);
    printf("Result of matrix multiplication is: \n");
    show(c,nra,ncb);
  }
  else
    printf("Two given Matrices do not conform to multiplication");
  getch();
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

Output2:

Enter the number of rows and columns of first matrix: 2  3
Enter the number of rows and columns of second matrix: 2  3
Matrices A and B do not conform to multiplication
*/

