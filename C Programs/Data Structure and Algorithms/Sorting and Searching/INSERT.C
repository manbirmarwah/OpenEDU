/* Program to demonstrate straight / simple insertion sort  */

#include  <stdio.h>
#include  <conio.h>

void  insert(int  x[ ] , int  n) ; 
void  show(int  x[ ] , int  n) ;

void  main()
{
 int  i , n , x[20] ;

 clrscr() ;

 printf("Enter the number of elements: ") ;
 scanf("%d",&n) ;
 printf("Enter the elements:\n") ;
 for(i=0 ; i<n ; i++)
    scanf("%d",&x[i]) ;

 insert(x,n) ;

 printf("Sorted array is as shown:\n") ;
 for(i=0 ; i<n ; i++)
    printf("%d " , x[i]) ;

 getch() ;
}

void  insert(int  x[ ] , int  n)
{
 int  i , j , y ;

 for(i=1 ; i<n ; i++)
 {
   y=x[i] ;
   for(j=i-1 ; j>=0&&y<x[j] ; j--)  
       x[j+1]=x[j] ;
   x[j+1]=y ;

   show(x,n) ;
 }
}

void  show(int  x[ ] , int  n)
{
  int  i ;
  for(i=0 ; i<n ; i++)
    printf("%d " , x[i]) ;
  printf("\n\n") ;
}


/* For descending order the condition y<x[j] will become y>x[j] */

/* The method show() is optional. It is written to show output of each pass. It may not be written in theory exam. It is required only in practical exams */

