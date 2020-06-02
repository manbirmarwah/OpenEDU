/* Program to demonstrate shell sort */

#include  <stdio.h>
#include  <conio.h>

void  shell(int x[],int n) ;
void  show(int x[],int n) ;

void  main()
{
 int  i , n , x[20] ;

 clrscr() ;

 printf("Enter the number of elements: ") ;
 scanf("%d",&n) ;
 printf("Enter the elements:\n") ;
 for(i=0;i<n;i++)
    scanf("%d",&x[i]) ;

 shell(x,n) ;

 printf("Sorted array is as shown:\n") ;
 for(i=0;i<n;i++)
    printf("%d ",x[i]) ;

 getch() ;
}

void  shell(int  x[ ] , int  n)
{
 int  i , j , y , incr ;

 incr=n/2 ;
 while(incr>=1)
 {
   printf("incr=%d \n",incr) ;

   /* Insertion sort*/
   for(i=incr ; i<n ; i++)
   {
     y=x[i] ;
     for(j=i-incr ; j>=0&&y<x[j] ; j=j-incr)
	 x[j+incr]=x[j] ;
     x[j+incr]=y ;

     show(x,n) ;
   }
   /* end of insertion sort*/

   incr=incr/2 ;
 }
}


void  show(int  x[ ] , int  n)
{
  int  i ;
  for(i=0 ; i<n ; i++)
    printf("%d ", x[i]) ;
  printf("\n\n") ;
}

