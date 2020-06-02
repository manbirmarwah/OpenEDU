/* Program to demonstrate MODIFIED bubble sort */

#include  <stdio.h>
#include  <conio.h>

void  bubble(int  x[ ] , int  n) ; 
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

 bubble(x,n) ;

 printf("Sorted array is as shown:\n") ;
 for(i=0 ; i<n ; i++)
    printf("%d " , x[i]) ;

 getch() ;
}

void  bubble(int  x[ ] , int  n)
{
 int  i , j , temp ; 
 int  flag=1 ;

 for(i=0 ; i<n-1&&flag==1 ; i++)
 {
   flag=0 ;

   for(j=0 ; j<n-1-i ; j++)
     if(x[j]>x[j+1])
     {
       temp=x[j] ;
       x[j]=x[j+1] ;
       x[j+1]=temp ;

       flag=1 ;
     }

   show(x,n) ;
 }
}

/* For descending order use x[j]<x[j+1] instead of x[j]>x[j+1] */

/* This is modified bubble sort. There is something called classical bubble sort also. 
Modified bubble sort has the ability to terminate the function earlier if the array gets sorted before reaching the last pass.
To convert modified bubble sort to classical bubble sort, just remove all the statements related with flag */

void  show(int  x[ ] , int  n)
{
  int  i ;
  for(i=0 ; i<n ; i++)
    printf("%d " , x[i]) ;
  printf("\n\n") ;
}

/* The method show() is optional. It is written to show output of each pass. It may not be written in theory exam. It is required only in practical exams */