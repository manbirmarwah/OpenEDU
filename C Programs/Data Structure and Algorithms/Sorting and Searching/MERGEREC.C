/* Program to demonstrate recursive merge sort */

#include  <stdio.h>
#include  <conio.h>

void  mergesort(int  x[ ] , int  lb , int  ub) ;
void merge(int  x[ ] , int  lb1 , int  ub1 , int  ub2) ;
void  show(int  x[ ] , int  lb , int  ub) ;

void  main()
{
 int  i , n , x[20] ;

 clrscr() ;

 printf("Enter the number of elements: ") ;
 scanf("%d",&n) ;
 printf("Enter the elements:\n") ;
 for(i=0 ; i<n ; i++)
    scanf("%d",&x[i]) ;

 mergesort(x,0,n-1) ;

 printf("Sorted array is as shown:\n") ;
 for(i=0 ; i<n ; i++)
    printf("%d " , x[i]) ;

 getch() ;
}

void  mergesort(int  x[ ] , int  lb , int  ub)
{
  int  mid ;
  if(lb<ub)
  {
    mid=(lb+ub)/2 ;
    mergesort(x,lb,mid) ;
    mergesort(x,mid+1,ub) ;
    merge(x,lb,mid,ub) ;
  }
}

void  merge(int  x[ ] , int  lb1 , int  ub1 , int  ub2)
{
  int  temp[50] , i , j , k ;

  i=lb1 ;
  j=ub1+1 ;
  k=0 ;

  while(i<=ub1&&j<=ub2)
    if(x[i]<x[j])               /* use > for descending order */
      temp[k++]=x[i++] ;
    else
      temp[k++]=x[j++] ;

  while(i<=ub1)
    temp[k++]=x[i++] ;

  while(j<=ub2)
    temp[k++]=x[j++] ;

  for(i=lb1 , j=0 ; i<=ub2 ; i++ , j++)
    x[i]=temp[j] ;

  show(x,lb1,ub2) ;

}

void  show(int  x[ ] , int  lb , int  ub)
{
  int  i ;
  for(i=lb ; i<=ub ; i++)
    printf("%d " , x[i]) ;
  printf("\n\n") ;
}

/*  The method show() is optional. It is written to show output of each pass. It may not be written in theory exam. It is required only in practical exams */

