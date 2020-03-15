/* Matrix Sum - Program to find sum of diagonal elements, elements above diagonal and elements below diagonal of a given square matrix */

#include  <stdio.h>
#include  <conio.h>

void  main()
{
  int  x[10][10] , nr , nc , r , c , sumd=0 , suma=0 , sumb=0 ;

  clrscr() ;

  printf("Enter the number of rows and columns: ") ;
  scanf("%d %d", &nr , &nc) ;

  printf("Enter elements of the matrix row-wise: \n") ;
  for(r=0 ; r<nr ; r++)
    for(c=0 ; c<nc ; c++)
        scanf("%d" , &x[r][c]) ;

  for(r=0 ; r<nr ; r++)
    for(c=0 ; c<nc ; c++)
    {
      if(r==c)
        sumd = sumd + x[r][c] ;
      if(r<c)
        suma = suma + x[r][c] ;
      if(r>c)
        sumb = sumb + x[r][c] ;
     }

  printf("The sum of all diagonal elements is %d \n" , sumd) ;
  printf("The sum of elements above diagonal is %d \n" , suma) ;
  printf("The sum of elements below diagonal is %d \n" , sumb) ;

  getch() ;
}

/* The following logic is also correct
  for(r=0 ; r<nr ; r++)
    for(c=0 ; c<nc ; c++)
    {
      if(r==c)
        sumd = sumd + x[r][c] ;
      if(r<c)
      {
        suma = suma + x[r][c] ;
        sumb = sumb + x[c][r] ;  <---- SEE HERE CAREFULLY
      }
    }
*/


/*
Output:

Enter the number of rows and columns: 3 3
Enter elements of the matrix row-wise: 
1 2 3
4 5 6
7 8 9
The sum of all diagonal elements is 15 
The sum of elements above diagonal is 11 
The sum of elements below diagonal is 19 
*/





