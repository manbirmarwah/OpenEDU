/* Program to demonstrate Randomized quick sort (recursive) */

#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

void  quick(int  x[] , int  lb , int  ub) ;
int  partition(int  x[] , int  lb , int  ub) ;
void  show(int  x[] , int  lb , int  ub) ;

void  main()
{
  int  i , n , x[20] ;

  clrscr() ;

  printf("Enter the number of elements: ") ;
  scanf("%d",&n) ;
  printf("Enter the elements:\n") ;
  for(i=0;i<n;i++)
    scanf("%d",&x[i]) ;

  quick(x,0,n-1) ;

  printf("Sorted array is as shown:\n") ;
  for(i=0;i<n;i++)
    printf("%d ",x[i]) ;

  getch() ;
}

void  quick(int  x[] , int  lb , int  ub)
{
  int   j , k , temp ;

  if(lb<ub)
  {   
    k=rand()%(ub-lb+1) + lb ;

    temp=x[k] ;
    x[k]=x[lb] ;
    x[lb]=temp ;

    j=partition(x,lb,ub) ;
    quick(x,lb,j-1) ;
    quick(x,j+1,ub) ;
  }
}

int  partition(int  x[] , int  lb , int  ub)
{
  int  a , down , up , temp ;

  a=x[lb] ;
  up=ub ;
  down=lb ;

  while(down<up)
  {
    while(x[down]<=a&&down<ub)
	down++ ;
    while(x[up]>a)
	up-- ;
    if(down<up)
    {
	 temp=x[down] ;
	 x[down]=x[up] ;
	 x[up]=temp ;
    }
  }

  x[lb]=x[up] ;
  x[up]=a ;

  show(x,lb,ub) ;

  return  up ;
}

void  show(int  x[] , int  lb , int  ub)
{
  int  i ;
  for(i=lb ; i<=ub ; i++)
    printf("%d ",x[i]) ;
  printf("\n\n") ;
}

 /* The method show() is optional. It is written to show output of each pass. It may not be written in theory exam. It is required only in practical exams */
