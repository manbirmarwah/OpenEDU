/* Program to demonstrate straight selection sort or push down sort */

#include  <stdio.h>
#include  <conio.h>

void  select(int  x[ ] , int  n) ;
void  show(int  x[ ] , int  n) ;

void  main()
{
 int  i , n , x[20] ;

 clrscr() ;

 printf("Enter the number of elements: ") ;
 scanf("%d",&n) ;
 printf("Enter the elements:\n") ;
 for(i=0;i<n;i++)
    scanf("%d",&x[i]) ;

 select(x,n) ;

 printf("Sorted array is as shown:\n") ;
 for(i=0;i<n;i++)
    printf("%d ",x[i]) ;

 getch() ;
}

void  select(int  x[ ] , int  n)
{
 int  i , j , index , max ;

 for(i=n-1 ; i>0 ; i--)
 {
   max=x[0] ;
   index=0 ;
   for(j=1 ; j<=i ; j++)
     if(x[j]>max)          
     {
       max=x[j] ;
       index=j ;
     }

   x[index]=x[i] ;
   x[i]=max ;

   show(x,n) ;
 }
}

/* change x[j]>max to x[j]<min for Descending order */

void  show(int  x[ ] , int  n)
{
  int  i ;
  for(i=0 ; i<n ; i++)
    printf("%d " , x[i]) ;
  printf("\n\n") ;
}

/* The method show() is optional. It is written to show output of each pass. It may not be written in theory exam. It is required only in practical exams */
