/* Program to demonstrate Interpolation search */

/* We assume that the array is sorted in ascending order */

#include  <stdio.h>
#include  <conio.h>

int  interpolation(int  x[ ] , int  n , int  key) ;

void  main()
{
 int  i , n , x[20] , key ;

 clrscr() ;

 printf("Enter the number of elements: ") ;
 scanf("%d",&n) ;
 printf("Enter the elements:\n") ;
 for(i=0 ; i<n ; i++)
    scanf("%d",&x[i]) ;

 printf("Enter the element to be searched: ") ;
 scanf("%d",&key) ;

 i=interpolation(x,n,key) ;

  if(i==-1)
     printf("%d not found." , key) ;
  else
     printf("%d found at position %d." , key,i) ;

 getch() ;
}

int  interpolation(int  x[ ] , int  n , int  key)
{
  int low,high,mid;

  low=0;
  high=n-1;

  while(low<=high)
  {
    /* ONLY DIFFERENCE BETWEEN BINARY AND INTERPOLATION SEARCH */
    mid = low + (high-low) * ( (key-x[low]) / (x[high]-x[low]) );

    if(key==x[mid])
      return mid;
    else if(key<x[mid])
      high=mid-1;
    else
      low=mid+1;
  }

  return-1;
}
